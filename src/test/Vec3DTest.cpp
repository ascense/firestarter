
#include <unittest++/UnitTest++.h>

#include "../lib/Lib.hpp"


SUITE(Vec3D) {
    struct Vec3DFixture {
        Firestarter::Lib::Vec3D *vec1, *vec2;

        Vec3DFixture() {
            vec1 = new Firestarter::Lib::Vec3D(1, 2, 3);
            vec2 = new Firestarter::Lib::Vec3D(3, 4, 5);
        }

        ~Vec3DFixture() {
            delete vec1;
            delete vec2;
        }
    };


    TEST_FIXTURE(Vec3DFixture, Vec3DConstructor) {
        CHECK_EQUAL(1, vec1->getX());
        CHECK_EQUAL(2, vec1->getY());
        CHECK_EQUAL(3, vec1->getZ());

        CHECK_EQUAL(3, vec2->getX());
        CHECK_EQUAL(4, vec2->getY());
        CHECK_EQUAL(5, vec2->getZ());

        Firestarter::Lib::Vec3D *vec = new Firestarter::Lib::Vec3D();
        CHECK_EQUAL(0, vec->getX());
        CHECK_EQUAL(0, vec->getY());
        CHECK_EQUAL(0, vec->getZ());
        delete vec;

        vec = new Firestarter::Lib::Vec3D(vec1);
        CHECK_EQUAL(vec1->getX(), vec->getX());
        CHECK_EQUAL(vec1->getY(), vec->getY());
        CHECK_EQUAL(vec1->getZ(), vec->getZ());
        delete vec;
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DGetValueException) {
        CHECK_THROW(vec1->getValue(0), Firestarter::Lib::FirestarterException);
        CHECK_THROW(vec2->getValue(4), Firestarter::Lib::FirestarterException);
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DSetValue) {
        vec1->setValue(1, 5);
        vec1->setValue(2, 10);
        vec1->setValue(3, 15);

        CHECK_EQUAL(5, vec1->getValue(1));
        CHECK_EQUAL(10, vec1->getValue(2));
        CHECK_EQUAL(15, vec1->getValue(3));

        CHECK_EQUAL(vec1->getX(), vec1->getValue(1));
        CHECK_EQUAL(vec1->getY(), vec1->getValue(2));
        CHECK_EQUAL(vec1->getZ(), vec1->getValue(3));
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DSetValueException) {
        CHECK_THROW(vec1->setValue(0, 1), Firestarter::Lib::FirestarterException);
        CHECK_THROW(vec2->setValue(4, 2), Firestarter::Lib::FirestarterException);
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DAddition) {
        vec1->add(vec2);
        CHECK_EQUAL(4, vec1->getX());
        CHECK_EQUAL(6, vec1->getY());
        CHECK_EQUAL(8, vec1->getZ());

        vec2->add(vec1);
        CHECK_EQUAL(7, vec2->getX());
        CHECK_EQUAL(10, vec2->getY());
        CHECK_EQUAL(13, vec2->getZ());
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DSubtraction) {
        vec2->subtract(vec1);
        CHECK_EQUAL(2, vec2->getX());
        CHECK_EQUAL(2, vec2->getY());
        CHECK_EQUAL(2, vec2->getZ());

        vec1->subtract(vec2);
        CHECK_EQUAL(-1, vec1->getX());
        CHECK_EQUAL(0, vec1->getY());
        CHECK_EQUAL(1, vec1->getZ());
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DMultiplication) {
        vec1->multiply(3);
        CHECK_EQUAL(3, vec1->getX());
        CHECK_EQUAL(6, vec1->getY());
        CHECK_EQUAL(9, vec1->getZ());

        vec2->multiply(2);
        CHECK_EQUAL(6, vec2->getX());
        CHECK_EQUAL(8, vec2->getY());
        CHECK_EQUAL(10, vec2->getZ());
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DMirrorAxis) {
        vec1->mirrorAxis(1);
        CHECK_EQUAL(-1, vec1->getX());
        CHECK_EQUAL(2, vec1->getY());
        CHECK_EQUAL(3, vec1->getZ());

        vec1->mirrorAxis(2);
        CHECK_EQUAL(-1, vec1->getX());
        CHECK_EQUAL(-2, vec1->getY());
        CHECK_EQUAL(3, vec1->getZ());
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DDotProduct) {
        CHECK_EQUAL(26, Firestarter::Lib::Vec3D::dotProduct(vec1, vec2));
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DOperatorEquals) {
        CHECK(*vec1 != *vec2);

        vec2->setX(1);
        vec2->setY(2);
        vec2->setZ(3);

        CHECK(*vec1 == *vec2);
    }


    TEST_FIXTURE(Vec3DFixture, Vec3DOperatorCompoundAssign) {
        *vec1 += *vec2;
        CHECK_EQUAL(4, vec1->getX());
        CHECK_EQUAL(6, vec1->getY());
        CHECK_EQUAL(8, vec1->getZ());

        *vec1 -= *vec2;
        CHECK_EQUAL(1, vec1->getX());
        CHECK_EQUAL(2, vec1->getY());
        CHECK_EQUAL(3, vec1->getZ());
    }
}

