
# **C Programming Guide – Part 1**


# **1. What is C Language? — يعني إيه لغة C؟**

**C is a fast, powerful, low-level programming language used to build operating systems, embedded systems, compilers, and high-performance applications.**
لغة **C** لغة قوية وسريعة ومنخفضة المستوى، وبتستخدم في بناء أنظمة التشغيل، وبرامج الـ Embedded، والـ Compilers، والبرامج اللي محتاجة أداء عالي.

**It teaches you how computers work internally: memory, CPU operations, data layout.**
وبتعلّمك الكمبيوتر بيشتغل إزاي جوّه: الذاكرة، المعالج، وترتيب البيانات.

---

# **2. Structure of a C Program — شكل برنامج الـ C**

```c
#include <stdio.h>     // Library

int main(void) {       // Program entry point
    printf("Hello World!\n");  
    return 0;          
}
```

### **Explanation — الشرح**

* **`#include <stdio.h>` → imports input/output functions like `printf`.**
  يستدعي مكتبة فيها دوال الإدخال والإخراج زي `printf`.

* **`main()` → the starting point of every C program.**
  نقطة بداية أي برنامج C.

* **`return 0;` → means program ended successfully.**
  معناها إن البرنامج خلص بدون مشاكل.

---

# **3. Comments — التعليقات**

### **Single-line comment — تعليق سطر واحد**

```c
// This is a comment   // دا تعليق
```

### **Multi-line comment — تعليق لأكتر من سطر**

```c
/*
   This is a multi-line comment    // دا تعليق طويل
*/
```

---

# **4. Variables — المتغيرات**

**A variable is a container that stores a value in memory.**
المتغير هو صندوق في الذاكرة بيخزن قيمة.

---

## **Basic Types — الأنواع الأساسية**

| Type     | Meaning     | Format | العربي           |
| -------- | ----------- | ------ | ---------------- |
| `int`    | integer     | `%d`   | عدد صحيح         |
| `float`  | decimal     | `%f`   | رقم عشري         |
| `double` | big decimal | `%lf`  | رقم عشري كبير    |
| `char`   | character   | `%c`   | حرف واحد         |
| `char[]` | string      | `%s`   | نص (مصفوفة حروف) |
| `bool`   | true/false  | `%d`   | صحيح/خطأ         |

---

## **Example — مثال**

```c
#include <stdio.h>
#include <stdbool.h>

int main() {
    int age = 20;            // int → عدد صحيح
    float gpa = 3.5f;        // float → رقم عشري
    double salary = 5500.75; // double → رقم عشري كبير
    char grade = 'A';        // char → حرف واحد
    char name[] = "Yousef";  // string → نص
    bool isOnline = true;    // bool → منطقي

    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Salary: %lf\n", salary);
    printf("Grade: %c\n", grade);
    printf("Name: %s\n", name);
    printf("Online: %d\n", isOnline);
}
```

---

# **5. Format Specifiers & Width — التنسيق وعرض الطباعة**

**You can control how numbers appear in output.**
تقدر تتحكم في شكل الرقم وهو بيطبع.

```c
int n = 5;

printf("%3d\n", n);    // "  5"   → العرض 3 (مسافات)
printf("%03d\n", n);   // "005"   → عرض 3 مع أصفار
```

---

# **6. Taking Input from User — إدخال بيانات من المستخدم**

### **Using `scanf` (good for numbers & single words) — مناسب للأرقام والكلمة الواحدة**

```c
int age;
scanf("%d", &age);   // قراءة عدد صحيح
```

---

# **⚠️ Problem with scanf for strings — مشكلة scanf مع النصوص**

**`scanf("%s")` stops at the first space.**
يقف عند أول space → مش مناسب للأسماء الكاملة.

مثال:
إذا كتب المستخدم:
`Mohamed Ali`
البرنامج هياخد بس:
`Mohamed`

---

# **7. Reading Strings with Spaces — قراءة نصوص فيها مسافات**

### **Best method → `fgets` — أفضل طريقة**

```c
char name[30];

printf("Enter your name: ");
fgets(name, sizeof(name), stdin);   // تقرأ النص كامل بالمسافات

// Remove newline — إزالة \n
name[strcspn(name, "\n")] = '\0';

printf("Your name is %s\n", name);
```

### **Why fgets is better? — ليه fgets أفضل؟**

* تقرأ المسافات
* آمنة ومش بتخرج بره حجم المصفوفة
* مناسبة للأسماء الطويلة والجمل

---

# **🎯 نهاية الجزء الأول من الكورس**

اتعلمنا:

* يعني إيه لغة C
* شكل البرنامج
* التعليقات
* المتغيرات والأنواع
* الطباعة وعرض الحقول
* إدخال البيانات
* أفضل طريقة لقراءة النصوص

