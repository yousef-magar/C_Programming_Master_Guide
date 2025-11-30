# 🔥 Part 4 – **Structs + Enums + Typedef + Pointers (FULL PACKAGE)**

**THE MOST IMPORTANT PART IN C FOR EMBEDDED + OOP-STYLE PROGRAMMING**

---

# 1️⃣ `typedef struct` –

## ❗ الفكرة الأساسية

Normally you write:

```c
struct Car {
    char model[20];
    int year;
};
```

Then you must write:

```c
struct Car c1;
```

But with `typedef struct` أنت بتعمل *alias* — اسم مختصر
وبتخلي الكتابة سهلة زي اللغات الحديثة:

---

## ✅ الشكل الصح

```c
typedef struct {
    char model[25];
    int year;
    int price;
} Car;
```

**Car** بقت type جديد
زي int — float — char
وتقدر تعمل:

```c
Car car1 = {"Mustang", 2025, 32000};
```

---

## ❗ تصحيح خطأ عندك

إنت كاتب:

```c
printf("%s %d $%d\n", car01.model, car01.year, car1.price);
```

لكن المفروض:

```c
printf("%s %d $%d\n", car01.model, car01.year, car01.price);
                   // ---------------------- fixed
```

---

## 🔥 Array of Structs

```c
Car cars[] = {
    {"Mustang", 2025, 32000},
    {"Corvette", 2028, 58000},
    {"Challenger", 2022, 85000}
};
```

عدد العناصر:

```c
int count = sizeof(cars) / sizeof(Car);
```

Loop:

```c
for(int i = 0; i < count; i++){
    printf("%s %d $%d\n", cars[i].model, cars[i].year, cars[i].price);
}
```

---

## 🔥 تطبيق عملي (مهم جدًا ل Embedded)

### ✔ برنامج يطبع أغلى عربية

```c
Car getMostExpensive(Car arr[], int n) {
    Car max = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i].price > max.price){
            max = arr[i];
        }
    }
    return max;
}
```

---

# 2️⃣ POINTERS with STRUCTS

## ❗ دي مرحلة الاحتراف

### 📌 pointer to struct

```c
Car *p = &car1;
printf("%d", p->year);   // بدل p.year
```

**->** = access through pointer
**.** = access normal

---

## 🔥 تعديل struct من خلال pointer

```c
void increasePrice(Car *c){
    c->price += 5000;
}
```

---

# 3️⃣ Pointers Basics (Fixed Your Code)

إنت عامل:

```c
birthday(age); // ❌ age is int
```

لازم pointer:

```c
birthday(&age);  // ✔
```

---

## 🔥 الشكل الصحيح الكامل

```c
#include <stdio.h>

void birthday(int *age){
    (*age)++;
}

int main() {

    int age = 25;

    birthday(&age);

    printf("Age now: %d", age);

    return 0;
}
```

### ✔ ليه بتحصل زيادة فعلية؟

لأنك بتمرر **address**
مش نسخة من القيمة.

---

# 4️⃣ ENUM — أقوى حاجة تنظيمية في C

## ❗ بتستخدم ENUM ليه؟

* تخلي الكود مقروء
* تمنع أرقام سحرية
* تستخدم في **states** في embedded
* تستخدم في **modes** (AUTO — MANUAL — ERROR)

---

## الشكل الصحيح

```c
typedef enum {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} Day;
```

---

## 📌 استخدام ENUM

```c
Day today = MONDAY;

if(today == MONDAY){
    printf("Back to work!");
}
```

---

## 🔥 تدي قيمة معينة ل enum

```c
typedef enum {
    OFF = 0,
    ON = 1,
    ERROR = -1
} State;
```

---

# 5️⃣ Struct + Enum + Pointer

## ✨ ده بقى مستوى Embedded ECU Developer

### برنامج Sensors

حالة السنسور = Enum
بيانات السنسور = Struct
التحكم = Pointer

```c
typedef enum {
    SENSOR_OK,
    SENSOR_DISCONNECTED,
    SENSOR_FAULT
} SensorStatus;

typedef struct {
    char name[20];
    int value;
    SensorStatus status;
} Sensor;

void updateSensor(Sensor *s, int newValue){
    s->value = newValue;
    if(newValue < 0) s->status = SENSOR_FAULT;
}
```

---

# 6️⃣ STRUCT داخل STRUCT

## مثال على ECU System

```c
typedef struct {
    int rpm;
    int speed;
} EngineData;

typedef struct {
    EngineData engine;
    int batteryVoltage;
} CarECU;
```

---

# 7️⃣ تطبيق احترافي (كود كامل)

## System يحمل 3 طلاب ويطبع أفضل GPA

```c
typedef struct {
    char name[50];
    int age;
    float gpa;
    int isFullTime;
} Student;

Student top(Student arr[], int n){
    Student best = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i].gpa > best.gpa){
            best = arr[i];
        }
    }
    return best;
}
```

---
