#define BOOST_TEST_MODULE UnitTestSuite
#include <boost/test/included/unit_test.hpp>
#include "PLayer.h"
#include "PObject.h"
#include <Helper.h>
#include <PPlayer.h>
#include <QApplication>

BOOST_AUTO_TEST_CASE(Helper_checkcollision) {
    PPlayer* PPa = new PPlayer();
    PPlayer* PPb = new PPlayer();

    PPa->setPosition(QVector3D(0,0,0));
    PPb->setPosition(QVector3D(0,0,0));
    BOOST_CHECK(Helper::checkCollision(PPa, PPb) == 1);

    // Change position
    PPa->setPosition(QVector3D(0.7f,0,0));
    PPb->setPosition(QVector3D(0,0.5f,0));
    BOOST_CHECK(Helper::checkCollision(PPa, PPb) == 0);


    // Check change type
    PPa->setTypePrint(GL_QUADS);
    BOOST_CHECK(Helper::checkCollision(PPa, PPb) == -1);

    PPa->setTypePrint(GL_LINES);
    BOOST_CHECK(Helper::checkCollision(PPa, PPb) == -1);

    delete PPa;
    delete PPb;
}

BOOST_AUTO_TEST_CASE(PConfig_SetAndGetKeysControl) {
    PConfig fixture;

    QMap<PConfig::key, int> keys;
    keys[PConfig::key::Up] = Qt::Key::Key_A;
    keys[PConfig::key::Down] = Qt::Key::Key_H;

    fixture.setKeysControl(keys);

    auto keys_a = fixture.getKeysControl();

    BOOST_CHECK(keys == keys_a);
}

BOOST_AUTO_TEST_CASE(PEvents_InitAndGetElements) {
    PEvents fixture;

    auto elements = fixture.getElements();

    BOOST_CHECK(elements.length() == 0);
}

BOOST_AUTO_TEST_CASE(PEvents_SetAndGetElements) {
    PEvents fixture;

    QList<PObject *> elements = QList<PObject *>();
    BOOST_CHECK(elements.length() == 0);

    elements.append(new PObject());
    BOOST_CHECK(elements.length() == 1);

    fixture.setElements(elements);
    auto elements_ = fixture.getElements();
    BOOST_CHECK(elements_.length() == 1);
}

BOOST_AUTO_TEST_CASE(PEvents_ValueSetAndValueGetElements) {
    PEvents fixture;

    QList<PObject *> elements = QList<PObject *>();
    BOOST_CHECK(elements.length() == 0);

    elements.append(new PObject());
    BOOST_CHECK(elements.length() == 1);

    fixture.setElements(elements);
    auto elements_ = fixture.getElements();
    BOOST_CHECK(elements_.length() == 1);
}

BOOST_AUTO_TEST_CASE(PLayer_InitAndGetColorBackground) {

    PLayer fixture;
    auto vec3 = fixture.getColorBackground();
    auto vec3_ = QVector3D(0,0,0);

    BOOST_CHECK(
        vec3.x() == vec3_.x() &&
        vec3.y() == vec3_.y() &&
        vec3.z() == vec3_.z()
    );

};

BOOST_AUTO_TEST_CASE(PLayer_SetAndGetColorBackground) {

    PLayer fixture;

    fixture.setColorBackground(QVector3D(250, 22, 8));

    auto vec3 = fixture.getColorBackground();
    auto vec3_ = QVector3D(250, 22, 8);

    BOOST_CHECK(
        vec3.x() == vec3_.x() &&
        vec3.y() == vec3_.y() &&
        vec3.z() == vec3_.z()
    );

};

BOOST_AUTO_TEST_CASE(PLayer_InitAndGetElements) {
    PLayer fixture;

    auto elements = fixture.getElements();

    BOOST_CHECK(elements.length() == 0);
}

BOOST_AUTO_TEST_CASE(PLayer_SetAndGetElements) {
    PLayer fixture;

    QList<PObject *> elements = QList<PObject *>();
    BOOST_CHECK(elements.length() == 0);

    elements.append(new PObject());
    BOOST_CHECK(elements.length() == 1);

    fixture.setElements(elements);
    auto elements_ = fixture.getElements();
    BOOST_CHECK(elements_.length() == 1);
}

BOOST_AUTO_TEST_CASE(PLayer_ValueSetAndValueGetElements) {
    PLayer fixture;

    QList<PObject *> elements = QList<PObject *>();
    BOOST_CHECK(elements.length() == 0);

    elements.append(new PObject());
    BOOST_CHECK(elements.length() == 1);

    fixture.setElements(elements);
    auto elements_ = fixture.getElements();
    BOOST_CHECK(elements_.length() == 1);
}

BOOST_AUTO_TEST_CASE(PObject_InitAndGetPosition) {
    PObject fixture;

    auto vec3 = fixture.getPosition();
    auto vec3_ = QVector3D(0,0,0);

    BOOST_CHECK(
        vec3.x() == vec3_.x() &&
        vec3.y() == vec3_.y() &&
        vec3.z() == vec3_.z()
    );

}

BOOST_AUTO_TEST_CASE(PObject_SetAndGetPosition) {
    PObject fixture;

    auto vec3 = fixture.getPosition();
    auto vec3_ = QVector3D(0,0,0);

    BOOST_CHECK(
        vec3.x() == vec3_.x() &&
        vec3.y() == vec3_.y() &&
        vec3.z() == vec3_.z()
    );

    fixture.setPosition(QVector3D(13, 20, 45));
    auto vec3_1 = fixture.getPosition();
    auto vec3_1_ = QVector3D(13, 20, 45);

    BOOST_CHECK(
        vec3_1.x() == vec3_1_.x() &&
        vec3_1.y() == vec3_1_.y() &&
        vec3_1.z() == vec3_1_.z()
    );
}

BOOST_AUTO_TEST_CASE(PObject_InitAndGetTypePrint) {
    PObject fixture;

    auto type = fixture.getTypePrint();
    BOOST_CHECK(type == GL_TRIANGLES);
}

BOOST_AUTO_TEST_CASE(PObject_SetAndGetTypePrint) {
    PObject fixture;

    auto type = fixture.getTypePrint();
    BOOST_CHECK(type == GL_TRIANGLES);

    fixture.setTypePrint(GL_LINE_LOOP);
    BOOST_CHECK(fixture.getTypePrint() == GL_LINE_LOOP);
}

BOOST_AUTO_TEST_CASE(PObject_InitAndGetShape) {
    PObject fixture;

    auto shape = fixture.getShape();
    BOOST_CHECK(shape.length() == 0);
}

BOOST_AUTO_TEST_CASE(PObject_SetAndGetShape) {
    PObject fixture;

    auto shape = fixture.getShape();
    BOOST_CHECK(shape.length() == 0);

    auto shape_ = QVector<GLfloat>();
    shape_.append(0.3f);
    fixture.setShape(shape_);
    BOOST_CHECK(shape_.length() == 1);
}

BOOST_AUTO_TEST_CASE(PObject_ValueSetAndValueGetShape) {
    PObject fixture;

    auto shape = fixture.getShape();
    BOOST_CHECK(shape.length() == 0);

    auto shape_ = QVector<GLfloat>();
    shape_.append(0.3f);
    fixture.setShape(shape_);
    BOOST_CHECK(shape_.length() == 1);

    BOOST_CHECK(shape_.first() == 0.3f);
    BOOST_CHECK(shape_.at(0) == 0.3f);
}

BOOST_AUTO_TEST_CASE(PObject_InitAndGetFragment) {
    PObject fixture;

    auto shape = fixture.getFragment();
    BOOST_CHECK(shape.length() == 0);
}

BOOST_AUTO_TEST_CASE(PObject_SetAndGetFragment) {
    PObject fixture;

    auto shape = fixture.getFragment();
    BOOST_CHECK(shape.length() == 0);

    auto fragment_ = QVector<GLint>();
    fragment_.append(20);
    fixture.setFragment(fragment_);
    BOOST_CHECK(fragment_.length() == 1);
}

BOOST_AUTO_TEST_CASE(PObject_ValueSetAndValueGetFragment) {
    PObject fixture;

    auto fragment = fixture.getFragment();
    BOOST_CHECK(fragment.length() == 0);

    auto fragment_ = QVector<GLint>();
    fragment_.append(13);
    fixture.setFragment(fragment_);
    BOOST_CHECK(fragment_.length() == 1);

    BOOST_CHECK(fragment_.first() == 13);
    BOOST_CHECK(fragment_.at(0) == 13);
}

BOOST_AUTO_TEST_CASE(PPlayer_SetAndGetScore) {
    PPlayer fixture;

    auto score = fixture.getScore();
    BOOST_CHECK(score == 0);

    fixture.setScore(11);
    auto score_1 = fixture.getScore();
    BOOST_CHECK(score_1 == 11);

    fixture.setScore(-5);
    auto score_2 = fixture.getScore();
    BOOST_CHECK(score_2 > 0);

}

