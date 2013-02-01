
#include <unittest++/UnitTest++.h>

#include "lib/Lib.hpp"


SUITE(AABB2D) {
    struct AABB2DFixture {
        Firestarter::Lib::AABB2D *box;

        AABB2DFixture() {
            box = new Firestarter::Lib::AABB2D(0, 0);
        }

        ~AABB2DFixture() {
            delete box;
        }
    };


    TEST_FIXTURE(AABB2DFixture, AABB2DConstructor) {
        Firestarter::Lib::Vec2D *vec;

        vec = box->getMinCoords();
        CHECK_EQUAL(0, vec->getX());
        CHECK_EQUAL(0, vec->getY());
        delete vec;

        vec = box->getMaxCoords();
        CHECK_EQUAL(0, vec->getX());
        CHECK_EQUAL(0, vec->getY());
        delete vec;

        vec = new Firestarter::Lib::Vec2D(1, 5);

        delete box;
        box = new Firestarter::Lib::AABB2D(vec);
        delete vec;

        vec = box->getMinCoords();
        CHECK_EQUAL(1, vec->getX());
        CHECK_EQUAL(5, vec->getY());
        delete vec;

        vec = box->getMaxCoords();
        CHECK_EQUAL(1, vec->getX());
        CHECK_EQUAL(5, vec->getY());
        delete vec;
    }


    TEST_FIXTURE(AABB2DFixture, AABB2DSetCoords) {
        Firestarter::Lib::Vec2D *vec;

        vec = new Firestarter::Lib::Vec2D(-5, 1);
        box->setMinCoords(vec);
        delete vec;

        vec = box->getMinCoords();
        CHECK_EQUAL(-5, vec->getX());
        CHECK_EQUAL(1, vec->getY());
        delete vec;

        vec = box->getMaxCoords();
        CHECK_EQUAL(0, vec->getX());
        CHECK_EQUAL(1, vec->getY());
        delete vec;

        vec = new Firestarter::Lib::Vec2D(-2, -2);
        box->setMaxCoords(vec);
        delete vec;

        vec = box->getMinCoords();
        CHECK_EQUAL(-5, vec->getX());
        CHECK_EQUAL(-2, vec->getY());
        delete vec;

        vec = box->getMaxCoords();
        CHECK_EQUAL(-2, vec->getX());
        CHECK_EQUAL(-2, vec->getY());
        delete vec;
    }


    TEST_FIXTURE(AABB2DFixture, AABB2DAddCoords) {
        Firestarter::Lib::Vec2D *vec;

        vec = new Firestarter::Lib::Vec2D(-5, 1);
        box->addVector(vec);
        delete vec;

        vec = box->getMinCoords();
        CHECK_EQUAL(-5, vec->getX());
        CHECK_EQUAL(0, vec->getY());
        delete vec;

        vec = box->getMaxCoords();
        CHECK_EQUAL(0, vec->getX());
        CHECK_EQUAL(1, vec->getY());
        delete vec;

        vec = new Firestarter::Lib::Vec2D(3, 3);
        box->addVector(vec);
        delete vec;

        vec = box->getMinCoords();
        CHECK_EQUAL(-5, vec->getX());
        CHECK_EQUAL(0, vec->getY());
        delete vec;

        vec = box->getMaxCoords();
        CHECK_EQUAL(3, vec->getX());
        CHECK_EQUAL(3, vec->getY());
        delete vec;
    }
}
