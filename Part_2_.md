
# 🔥 **C Programming – Full Deep Guide (PART 2)**

### (Functions – Conditions – Switch – Math Library – Input Handling – Logic – Scope)

**كل حاجة بالراحة، وبعُمق، ومن دماغي.**

---

# ------------------------------------

# ⭐ **SECTION 1 — Math Library in C (math.h)**

# ------------------------------------

مكتبة **math.h** من أهم المكتبات اللي هتتعامل معاها لو بتعمل أي حسابات متقدمة.

علشان تستخدمها:

```c
#include <math.h>
```

---

## 🔹 1. sqrt() — Square Root

**English:** returns the square root.
**Arabic:** جذر تربيعي.

```c
double result = sqrt(16); // 4
```

✔ لازم الـreturn يكون double لأن العمليات الحسابية الدقيقة بتحتاج double.

---

## 🔹 2. pow(x, y)

**English:** x to the power y
**Arabic:** x مرفوعة للأس y

```c
double result = pow(5, 3); // 125
```

---

## 🔹 3. ceil(x)

**Arabic:** تقرب لفوق

```c
ceil(2.1); // 3
ceil(2.00001); // 3
```

---

## 🔹 4. floor(x)

**Arabic:** تقرب لتحت

```c
floor(3.9); // 3
```

---

## 🔹 5. round(x)

**Arabic:** تقريب عادي حسب القيمة

```c
round(3.2); // 3
round(3.6); // 4
```

---

## 🔹 6. abs(x)

**Arabic:** القيمة المطلقة (لإزالة السالب)

```c
abs(-9); // 9
```

---

## 🔹 7. sin(x), cos(x), tan(x)

**ملاحظة مهمة جدًا:**
● الدوال دي بتستقبل **radians مش degrees**.
لو عايز تحول من degree → radian:

```c
double rad = degree * M_PI / 180;
```

مثال:

```c
double rad = 90 * M_PI / 180;
printf("%lf", sin(rad)); // 1
```

---

# ------------------------------------

# ⭐ **SECTION 2 — Conditions (if / else if / else)**

# ------------------------------------

الشروط في C هي الأساس في الـ decision making.
بتخلي برنامجك ذكي ويتحكم حسب الحالة.

---

## 🔥 Structure:

```c
if(condition){
    // code
}
else if(condition){
    // code
}
else{
    // code
}
```

---

## 🔥 أمثلة حقيقية من الحياة:

### Example 1 — Age Check

```c
int age;

printf("Enter your age: ");
scanf("%d", &age);

if(age >= 18){
    printf("You are an adult");
}
else if(age < 0){
    printf("Error: age cannot be negative\n");
}
else{
    printf("You are a child");
}
```

---

### Example 2 — Nested Conditions

**Nested conditions = if داخل if**

```c
int grade = 90;

if(grade >= 50){
    printf("Pass\n");

    if(grade >= 90){
        printf("Excellent");
    }
}
else{
    printf("Fail");
}
```

---

### Example 3 — Check multiple conditions

```c
if(temp > 30){
    printf("Hot");
}
else if(temp >= 20 && temp <= 30){
    printf("Warm");
}
else{
    printf("Cold");
}
```

---

# ------------------------------------

# ⭐ **SECTION 3 — Logical Operators (&&, ||, !)**

# ------------------------------------

## 🔹 AND — &&

لازم الشرطين يكونوا true

```c
if(age >= 18 && hasID == 1)
```

---

## 🔹 OR — ||

واحد بس من الشرطين كفاية

```c
if(day == 6 || day == 7)
    printf("Weekend");
```

---

## 🔹 NOT — !

يعكس القيمة

```c
if(!loggedIn){
    printf("Please login first");
}
```

---

# ------------------------------------

# ⭐ **SECTION 4 — Switch Case**

# ------------------------------------

الـ Switch أفضل من if/else لما الحالات ثابتة (زي الأيام – الشهور – القوائم).

---

## 🔥 example:

```c
int day;
printf("Enter day number: ");
scanf("%d", &day);

switch(day){
    case 1:
        printf("Monday");
        break;

    case 2:
        printf("Tuesday");
        break;

    case 3:
        printf("Wednesday");
        break;

    default:
        printf("Invalid day");
        break;
}
```

✔ IMPORTANT: لازم break
لو مفيش break → program يعمل fall-through (ينفذ اللي بعده).

---

## مثال فشيخ يبين أهمية break:

```c
int n = 2;

switch(n){
    case 1:
        printf("Case 1\n");
    case 2:
        printf("Case 2\n");
    case 3:
        printf("Case 3\n");
}
```

Output:

```
Case 2
Case 3
```

ليه؟
لأنه دخل case 2 وكمل على اللي بعدها.

---

# ------------------------------------

# ⭐ **SECTION 5 — Strings Input (fgets vs scanf)**

# ------------------------------------

### ❌ scanf("%s", name);

● بتقف عند أول space
● خطيرة لو المستخدم كتب أكتر من مساحة المصفوفة
● غالبًا مش بنستخدمها للـ full names

---

### ✔ fgets(name, size, stdin)

● تقرأ الجملة كلها بما فيهم spaces
● أمان أكتر

```c
char name[50];
printf("Enter your name: ");
fgets(name, sizeof(name), stdin);
```

لكن فيها مشكلة…
بتضيف "\n"
فنمسحها كده:

```c
name[strlen(name)-1] = '\0';
```

---

# ------------------------------------

# ⭐ **SECTION 6 — Functions (الدوال)**

# ------------------------------------

الدوال هي أهم concept في البرمجة.
هي اللي بتخلي البرنامج modular وقابل لإعادة الاستخدام.

---

## 🔥 Structure:

```c
returnType functionName(parameters){
    // code
    return value;
}
```

---

## Example — function without return

```c
void greet(){
    printf("Hello C programmer!\n");
}
```

---

## Example — function with parameters

```c
void welcome(char name[]){
    printf("Welcome %s!\n", name);
}
```

---

## Example — function with return

```c
int square(int x){
    return x * x;
}
```

---

# ------------------------------------

# ⭐ **SECTION 7 — Function Prototype**

# ------------------------------------

C لازم يعرف **شكل الدالة قبل استخدامها**.

لو كتبت:

```c
hello("Yousef");
```

قبل ما تعرّف الدالة → ERROR
الحل؟ تعمل prototype:

```c
void hello(char name[]);
```

---

## Structure of prototype:

```c
returnType functionName(type1 param1, type2 param2);
```

---

## مثال كامل:

```c
#include <stdio.h>

void sayHi(char name[]); // prototype

int main(){
    sayHi("Mohamed");
    return 0;
}

void sayHi(char name[]){
    printf("Hi %s", name);
}
```

---

# ------------------------------------

# ⭐ **SECTION 8 — Boolean Functions**

# ------------------------------------

## Using <stdbool.h>

```c
#include <stdbool.h>
```

---

## Example:

```c
bool isAdult(int age){
    if(age >= 18)
        return true;
    else
        return false;
}
```

استخدامها:

```c
if(isAdult(age)){
    printf("Welcome");
}
else{
    printf("Not allowed");
}
```

---

# ------------------------------------

# ⭐ **SECTION 9 — Variable Scope**

# ------------------------------------

الـ scope يعني المتغير بيعيش فين، ومين يقدر يشوفه.

---

## 1. Local Variables

**Arabic:** متغير محلي
بيعيش جوة `{}` بس.

```c
if(1){
    int a = 10;
}
// a هنا ERROR
```

---

## 2. Global Variables

**Arabic:** متغير عالمي
متاح لكل الدوال.

```c
int counter = 0;

void add(){
    counter++;
}
```

---

## 3. Shadowing

لو عملت متغير بنفس الاسم في بلوك تاني

```c
int x = 5;

{
    int x = 10; // shadows outer x
    printf("%d", x); // 10
}
```

---

# ------------------------------------

# ⭐ **SECTION 10 — Full Example Combining Everything**

# ------------------------------------

ده مثال فشيخ بيلم كل اللي فوق:

```c
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void greet(char name[]);
bool isAdult(int age);
double calcBMI(double weight, double height);

int main(){

    char name[50];
    int age;
    double weight, height;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your weight (kg): ");
    scanf("%lf", &weight);

    printf("Enter your height (m): ");
    scanf("%lf", &height);

    greet(name);

    if(isAdult(age)){
        printf("You are an adult.\n");
    }
    else{
        printf("You are under 18.\n");
    }

    double bmi = calcBMI(weight, height);
    printf("Your BMI = %.2lf\n", bmi);

    if(bmi < 18.5){
        printf("Underweight\n");
    }
    else if(bmi < 25){
        printf("Normal weight\n");
    }
    else{
        printf("Overweight\n");
    }

    return 0;
}

void greet(char name[]){
    printf("Hello %s!\n", name);
}

bool isAdult(int age){
    return age >= 18;
}

double calcBMI(double weight, double height){
    return weight / pow(height, 2);
}
```

---
