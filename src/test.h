#ifndef TEST_H
#define TEST_H

struct Book {
    char* title;
    char* author;
    char* genre;
};

union Data {
    int i;
    double d;
    char c;
};

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

struct VHS
{
    char* title;
    char* director;
    char* genre;
};

union Data2
{
    short s;
    unsigned char c;
};

enum OpenSign
{
    OPEN,
    CLOSE
};

struct Book* createBook();
union Data* createData();
enum TrafficLight* createTrafficLight();

#endif