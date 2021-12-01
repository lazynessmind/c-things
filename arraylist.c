#include <stdio.h>
#include <stdlib.h>

#define TRUE 69
#define FALSE 0

typedef struct Player {
    int age;
    char *name;
} Person;

int currentCapacity;
int size;
Person *elements;

void Init(int);
void Add(Person *);
Person Get(int index);
void Remove(int index);
void EnsureCapacity(void);
void Dump(int all); // 0 is false other is true like 69

void Init(int cap) {
    currentCapacity = cap;
    elements = malloc(cap * sizeof(Person));

    for (int i = 0; i < cap; ++i) {
        elements[i] = (Person) {.name = NULL, .age = 0};
    }
}

void Add(Person *person) {
    if (size + 1 > currentCapacity) {
        EnsureCapacity();
    }
    elements[size++] = *person;
}

Person Get(int index) {
    return elements[index];
}

void Remove(int index) {
    if (index > 0 && index < currentCapacity) {
        size--;
        for (int i = index - 1; i < currentCapacity - 1; ++i) {
            elements[i] = elements[i + 1];
        }
    }
}

void EnsureCapacity(void) {
    printf("Growing array from %i ", currentCapacity);
    currentCapacity = currentCapacity + (currentCapacity >> 1);
    realloc(elements, currentCapacity);
    printf("to %i.\n", currentCapacity);
}

void Dump(int dumpAll) {
    for (int i = 0; i < currentCapacity; ++i) {
        if(dumpAll != FALSE) {
            printf("%i\t{Name: %s -  Age: %i}\n", i, elements[i].name, elements[i].age);
        } else if(elements[i].name != NULL) {
            printf("%i\t{Name: %s -  Age: %i}\n", i, elements[i].name, elements[i].age);
        }
    }
}


//TODO: Check why is going kaboom when the array size is greater than the initial capacity and not equal to the new capacity.
int main() {

    Person marta = {.age = 10, .name = "Marta"};
    Person marco = {.age = 12, .name = "Marco"};
    Person joel = {.age = 15, .name = "Joel"};
    Person teresa = {.age = 11, .name = "Teresa"};
    Person ana = {.age = 12, .name = "Ana"};

    int initialCap = 10;
    Init(initialCap);

    Add(&marta);
    Add(&marco);
    Add(&joel);
    Add(&teresa);
    Add(&ana);
    Dump(FALSE);

    printf("==== Remove the element in index 1 and add it to the end =====\n");

    Remove(1);
    Add(&marta);
    Dump(FALSE);

    printf("Initial size: %i. Actual: %i. Number of elements: %i", initialCap, currentCapacity, size);

    free(elements);

    return 0;
}
