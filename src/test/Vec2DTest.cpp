
#include <unittest++/UnitTest++.h>

#include "../lib/Lib.hpp"


SUITE(Vec2D) {
    struct Vec2DFixture {
        Firestarter::Lib::Vec2D *vec1, *vec2;

        Vec2DFixture() {
            vec1 = new Firestarter::Lib::Vec2D(1, 2);
            vec2 = new Firestarter::Lib::Vec2D(3, 4);
        }

        ~Vec2DFixture() {
            delete vec1;
            delete vec2;
        }
    };


    TEST_FIXTURE(Vec2DFixture, Vec2DConstructor) {
        CHECK_EQUAL(1, vec1->getX());
        CHECK_EQUAL(2, vec1->getY());

        CHECK_EQUAL(3, vec2->getX());
        CHECK_EQUAL(4, vec2->getY());

        Firestarter::Lib::Vec2D *vec = new Firestarter::Lib::Vec2D();
        CHECK_EQUAL(0, vec->getX());
        CHECK_EQUAL(0, vec->getY());
        delete vec;

        vec = new Firestarter::Lib::Vec2D(vec1);
        CHECK_EQUAL(vec1->getX(), vec->getX());
        CHECK_EQUAL(vec1->getY(), vec->getY());
        delete vec;
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DGetValueException) {
        CHECK_THROW(vec1->getValue(0), Firestarter::Lib::FirestarterException);
        CHECK_THROW(vec2->getValue(3), Firestarter::Lib::FirestarterException);
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DSetValue) {
        vec1->setValue(1, 5);
        vec1->setValue(2, 10);

        CHECK_EQUAL(5, vec1->getValue(1));
        CHECK_EQUAL(10, vec1->getValue(2));

        CHECK_EQUAL(vec1->getX(), vec1->getValue(1));
        CHECK_EQUAL(vec1->getY(), vec1->getValue(2));
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DSetValueException) {
        CHECK_THROW(vec1->setValue(0, 1), Firestarter::Lib::FirestarterException);
        CHECK_THROW(vec2->setValue(3, 2), Firestarter::Lib::FirestarterException);
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DAddition) {
        vec1->add(vec2);
        CHECK_EQUAL(4, vec1->getX());
        CHECK_EQUAL(6, vec1->getY());

        vec2->add(vec1);
        CHECK_EQUAL(7, vec2->getX());
        CHECK_EQUAL(10, vec2->getY());
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DSubtraction) {
        vec2->subtract(vec1);
        CHECK_EQUAL(2, vec2->getX());
        CHECK_EQUAL(2, vec2->getY());

        vec1->subtract(vec2);
        CHECK_EQUAL(-1, vec1->getX());
        CHECK_EQUAL(0, vec1->getY());
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DMultiplication) {
        vec1->multiply(3);
        CHECK_EQUAL(3, vec1->getX());
        CHECK_EQUAL(6, vec1->getY());

        vec2->multiply(2);
        CHECK_EQUAL(6, vec2->getX());
        CHECK_EQUAL(8, vec2->getY());
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DMirrorAxis) {
        vec1->mirrorAxis(1);
        CHECK_EQUAL(-1, vec1->getX());
        CHECK_EQUAL(2, vec1->getY());

        vec1->mirrorAxis(2);
        CHECK_EQUAL(-1, vec1->getX());
        CHECK_EQUAL(-2, vec1->getY());
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DFlipAxes) {
        vec1->flipAxes();
        CHECK_EQUAL(2, vec1->getX());
        CHECK_EQUAL(1, vec1->getY());

        vec2->flipAxes();
        CHECK_EQUAL(4, vec2->getX());
        CHECK_EQUAL(3, vec2->getY());
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DDotProduct) {
        CHECK_EQUAL(11, Firestarter::Lib::Vec2D::dotProduct(vec1, vec2));
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DOperatorEquals) {
        CHECK(*vec1 != *vec2);

        vec2->setX(1);
        vec2->setY(2);

        CHECK(*vec1 == *vec2);
    }


    TEST_FIXTURE(Vec2DFixture, Vec2DOperatorCompoundAssign) {
        *vec1 += *vec2;
        CHECK_EQUAL(4, vec1->getX());
        CHECK_EQUAL(6, vec1->getY());

        *vec1 -= *vec2;
        CHECK_EQUAL(1, vec1->getX());
        CHECK_EQUAL(2, vec1->getY());
    }
}
