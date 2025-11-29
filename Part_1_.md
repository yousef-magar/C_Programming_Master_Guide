
# 🚀 **C Programming – Master Guide (Part 1)**

### **The Ultimate Beginner Foundation**

### **أساسيات لغة C – أقوى شرح للمبتدئين (الجزء الأول)**

---

# ⭐ 1. Introduction to C

## **What is C Language? — يعني إيه لغة C؟**

**C is a general-purpose, powerful, low-level programming language designed to give you full control over memory and hardware.**
لغة **C** هي لغة قوية ومنخفضة المستوى بتديك تحكّم كامل في الذاكرة والهاردوير.

**It’s the mother of most modern languages** like C++, Java, C#, Rust, and many system-level technologies.
وهي **أم لغات برمجة كتير** زي C++، Java، C#، Rust… إلخ.

You learn C → You understand how computers think.
اتعلم C → تفهم الكمبيوتر بيفكر إزاي فعلًا.

---

# ⭐ 2. Anatomy of a C Program

## **مكونات برنامج C**

لما تفتح أي برنامج C، غالبًا هتلاقي الشكل ده:

```c
#include <stdio.h>

int main(void) {
    printf("Hello World!\n");
    return 0;
}
```

### Breakdown — التفكيك

### ✔ `#include <stdio.h>`

Imports a library that allows printing, input/output, formatting.
يستدعي مكتبة بتديك دوال للطباعة والإدخال والإخراج.

---

### ✔ `int main(void)`

This is the **entry point** of your program.
دي **نقطة البداية** اللي البرنامج يبدأ منها.

Whatever you write inside `{ ... }` will run.
أي كود جواه بينفّذ.

---

### ✔ `return 0;`

Means: “Program finished successfully.”
يعني: “البرنامج انتهى بدون مشاكل”.

---

# ⭐ 3. Comments

## **التعليقات**

Comments are ignored by the compiler.
التعليقات بتتجاهل وما بتتنفّذش.

### Single-line — تعليق سطر واحد:

```c
// This is a comment
```

### Multi-line — تعليق طويل:

```c
/*
   Multi-line comment
*/
```

التعليقات علم مهم لأنها بتخلي الكود مفهوم في المستقبل.

---

# ⭐ 4. Variables

## **المتغيرات**

A **variable** is a *named space in memory* that stores a value.
المتغير هو "مكان في الذاكرة" مُسمّى بنخزن فيه قيمة.

### Example — مثال:

```c
int age = 21;
float gpa = 3.5f;
char grade = 'A';
char name[] = "Yousef";
```

---

# ⭐ 5. Data Types

## **أنواع البيانات الأساسية**

| Type     | Meaning          | Example  | Format | العربي    |
| -------- | ---------------- | -------- | ------ | --------- |
| `int`    | Integer          | 5, -10   | `%d`   | عدد صحيح  |
| `float`  | Small decimal    | 3.14f    | `%f`   | رقم عشري  |
| `double` | Large decimal    | 99.12345 | `%lf`  | عشري كبير |
| `char`   | Single character | 'A'      | `%c`   | حرف واحد  |
| `char[]` | String           | "Hello"  | `%s`   | نص        |
| `bool`   | true/false       | true     | `%d`   | منطقي     |

> Note: You must include `<stdbool.h>` for `bool`.
> يجب تضمين `<stdbool.h>` لاستخدام النوع bool.

---

# ⭐ 6. Printing Values

## **طباعة القيم**

You use the `printf` function.
تستخدم `printf`.

### Example:

```c
printf("Age: %d\n", age);
printf("GPA: %.2f\n", gpa);
printf("Name: %s\n", name);
```

The `%` symbols are **format specifiers** to tell the program what you're printing.
الـ `%` هي "محددات" بتقول للبرنامج نوع البيانات.

---

# ⭐ 7. Format Width

## **عرض الطباعة**

You can control how numbers appear:

```c
int n = 5;

printf("%3d\n", n);   //   5
printf("%03d\n", n);  // 005
```

مفيد في الطباعة المرتبة أو الجداول.

---

# ⭐ 8. Getting User Input

## **إدخال البيانات من المستخدم**

You use `scanf`.

### Example:

```c
int age;
scanf("%d", &age);
```

The `&` means “give me the address of the variable”.
الـ `&` معناها “هات عنوان المتغير في الذاكرة”.

---

# ⚠️ Problem with scanf for strings

## **مشكلة scanf مع النصوص**

`scanf("%s")` **stops at spaces**.
يقف عند أول space.

لو المستخدم كتب:

```
Mohamed Ali
```

هياخد بس:

```
Mohamed
```

---

# ⭐ 9. Reading Strings Properly

## **قراءة النصوص بطريقة صحيحة**

The best method is:

### ✔ `fgets()` — reads the full line including spaces

```c
char name[30];

printf("Enter name: ");
fgets(name, sizeof(name), stdin);

// Remove newline at the end
name[strcspn(name, "\n")] = '\0';

printf("Hello %s\n", name);
```

ليه أفضل؟

* يقرأ المسافات
* آمن
* مابيخرجش من حجم المصفوفة
* مناسب للأسماء والجمل الطويلة

---

# ⭐ 10. Full Example — المثال الشامل

```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int age;
    float gpa;
    char name[40];
    bool online = true;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter GPA: ");
    scanf("%f", &gpa);

    getchar(); // remove leftover newline

    printf("Enter full name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\n--- OUTPUT ---\n");
    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Name: %s\n", name);
    printf("Online: %d\n", online);

    return 0;
}
```

---
