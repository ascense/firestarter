/**
* Copyright (C) 2012 Henry Carlson
*
* This file is part of the Firestarter engine.
*
* The Firestarter engine is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* The Firestarter engine is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "managers/ServiceMgr.hpp"


namespace Firestarter { namespace Managers {

ServiceMgr::LookupEntry::LookupEntry(const std::string *name, int sys)
        : name(name), sys(sys), next(nullptr) {}


ServiceMgr::LookupEntry::~LookupEntry() {
    delete next;
}

ServiceMgr::ServiceMgr() : p_lookupSize(16) {
    p_lookup = new LookupEntry*[p_lookupSize];
    for (int i = 0; i < p_lookupSize; ++i)
        p_lookup[i] = nullptr;
}


ServiceMgr::~ServiceMgr() {
    std::vector<Systems::AbstractSystem*>::iterator it;
    for (it = p_systems.begin(); it < p_systems.end(); it++)
        delete *it;

    for (int i = 0; i < p_lookupSize; ++i)
        delete p_lookup[i];
    delete [] p_lookup;
}


void ServiceMgr::init() {
    std::vector<Systems::AbstractSystem*>::iterator it;
    for (it = p_systems.begin(); it < p_systems.end(); it++)
        (*it)->init();
}


void ServiceMgr::registerSystem(Systems::AbstractSystem *sys) {
    p_systems.push_back(sys);

    int id = calculateHash(sys->getName()) % p_lookupSize;
    if (p_lookup[id] == nullptr) {
        p_lookup[id] = new LookupEntry(sys->getName(), p_systems.size() - 1);
    } else {
        LookupEntry *entry = new LookupEntry(sys->getName(), p_systems.size() - 1);
        entry->next = p_lookup[id];
        p_lookup[id] = entry;
    }
}


Systems::AbstractSystem* ServiceMgr::getSystem(int sysid) {
    if (sysid < 0 || sysid >= p_systems.size())
        return nullptr;

    return p_systems.at(sysid);
}


int ServiceMgr::getSystemID(const std::string *name) {
    LookupEntry *entry = p_lookup[calculateHash(name) % p_lookupSize];

    if (entry == nullptr)
        return -1;

    while (entry->next != nullptr) {
        if (entry->name->compare(name->c_str()) != 0)
            entry = entry->next;
    }

    return entry->sys;
}


unsigned int ServiceMgr::calculateHash(const std::string *str) {
    const char *cstr = str->c_str();
    unsigned int hash = 0;

    for (unsigned int i = 0; i < 6; ++i) {
        if (i >= str->length())
            break;
        hash ^= cstr[i] << i;
    }

    return hash;
}

}} // Firestarter::Managers
