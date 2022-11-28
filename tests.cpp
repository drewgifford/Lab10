// tests.cpp
#include <gtest/gtest.h>

#include "HashNode.h"
#include "HashTable.h"
#include <string>

using namespace std;

TEST(HashTable, TestAdd1) {
    HashTable<int, string> table(100);

    table.addItem(1, "Hello");
    
    ASSERT_TRUE(table.getItem(1)->getValue() == "Hello");
}

TEST(HashTable, TestAdd2) {
    HashTable<int, string> table(100);

    table.addItem(1, "Hello");
    table.addItem(2, "Kid Named Finger");
    
    ASSERT_TRUE(table.contains(2));
}

TEST(HashTable, TestGetItem1) {
    HashTable<int, string> table(100);

    table.addItem(1, "Hello");
    table.addItem(2, "Kid Named Finger");
    table.addItem(3, "Wabbit Season");

    ASSERT_TRUE(table.getItem(1)->getValue() == "Hello");
}

TEST(HashTable, TestGetItem2) {
    HashTable<int, string> table(100);

    table.addItem(1, "Hello");
    table.addItem(2, "Kid Named Finger");
    table.addItem(3, "Wabbit Season");

    ASSERT_TRUE(table.getItem(2)->getValue() == "Kid Named Finger");
    ASSERT_TRUE(table.getItem(3)->getValue() == "Wabbit Season");
    ASSERT_TRUE(table.getItem(1)->getValue() != "Wabbit Season");
}

TEST(HashTable, TestContains1) {
    HashTable<int, string> table(100);

    table.addItem(1, "Hello");
    table.addItem(2, "Kid Named Finger");
    table.addItem(3, "Wabbit Season");
    table.addItem(4, "Rock and Stone");
    table.addItem(5, "Kirchh-off myself");
    table.addItem(6, "And as it always has been...");
    table.addItem(7, "The demon core was a spherical 6.2-kilogram (14 lb) subcritical mass of plutonium 89 millimetres (3.5 in) in diameter, manufactured during World War II by the United States nuclear weapon development effort, the Manhattan Project, as a fissile core for an early atomic bomb. The core was prepared for shipment as part of the third nuclear weapon to be used in Japan, but when Japan surrendered, the core was retained at Los Alamos for testing and potential later use. It was involved in two criticality accidents at the Los Alamos Laboratory on August 21, 1945, and May 21, 1946, each resulting in a fatality. Both experiments were designed to demonstrate how close the core was to criticality with a tamper, but in each case, the core was accidentally placed into a supercritical configuration. Physicists Harry Daghlian and Louis Slotin suffered acute radiation syndrome (ARS) and died soon after, while others present in the lab were also exposed.");
    ASSERT_TRUE(table.contains(7) == true);
}

TEST(HashTable, TestContains2) {
    HashTable<int, string> table(100);

    table.addItem(1, "Hello");
    table.addItem(2, "Kid Named Finger");
    table.addItem(3, "Wabbit Season");
    table.addItem(4, "Rock and Stone");
    table.addItem(5, "Kirchh-off myself");
    table.addItem(6, "And as it always has been...");
    table.addItem(7, "The demon core was a spherical 6.2-kilogram (14 lb) subcritical mass of plutonium 89 millimetres (3.5 in) in diameter, manufactured during World War II by the United States nuclear weapon development effort, the Manhattan Project, as a fissile core for an early atomic bomb. The core was prepared for shipment as part of the third nuclear weapon to be used in Japan, but when Japan surrendered, the core was retained at Los Alamos for testing and potential later use. It was involved in two criticality accidents at the Los Alamos Laboratory on August 21, 1945, and May 21, 1946, each resulting in a fatality. Both experiments were designed to demonstrate how close the core was to criticality with a tamper, but in each case, the core was accidentally placed into a supercritical configuration. Physicists Harry Daghlian and Louis Slotin suffered acute radiation syndrome (ARS) and died soon after, while others present in the lab were also exposed.");
    table.addItem(8, "1 gram of Uranium contains about 18 million kCal per gram (those are food Calories; capital C), or about 18 billion calories per gram (those are heat calories).");
    table.addItem(9, "On the day of the accident, Slotin's screwdriver slipped outward a fraction of an inch while he was lowering the top reflector, allowing the reflector to fall into place around the core. Instantly, there was a flash of blue light and a wave of heat across Slotin's skin; the core had become supercritical, releasing an intense burst of neutron radiation estimated to have lasted about a half second.");
    ASSERT_TRUE(table.contains(5) == true);
    ASSERT_TRUE(table.contains(1) == true);
}

TEST(HashTable, TestHash1){

    HashTable<int, string> table(5);

    int toHash = 8;

    ASSERT_EQ(table.hash(toHash), toHash % 5);
}

TEST(HashTable, TestHash2){

    HashTable<int, string> table(69);

    int toHash = 1975;

    ASSERT_EQ(table.hash(toHash), toHash % 69);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}