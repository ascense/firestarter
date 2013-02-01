
#include <unittest++/UnitTest++.h>

#include "lib/Lib.hpp"


SUITE(GeomFunc) {
    TEST(GeomCollidePointLine) {
        Firestarter::Lib::Vec2D vec(3, 2);
        Firestarter::Lib::Vec2D line1(4, 2);
        Firestarter::Lib::Vec2D line2(6, 0);

        CHECK(Firestarter::Lib::Geom::collide2D(&vec, &line1, &line2));
        CHECK(!Firestarter::Lib::Geom::collide2D(&vec, &line2, &line1));

        vec.setX(5.5f);
        vec.setY(1);

        CHECK(!Firestarter::Lib::Geom::collide2D(&vec, &line1, &line2));
        CHECK(Firestarter::Lib::Geom::collide2D(&vec, &line2, &line1));
    }
}
