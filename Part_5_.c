# 🌟 **الجزء الخامس – File Handling + Dynamic Memory Mastery**

## 🎯 **أولاً: الكتابة على الملفات – Writing to Files**

### 💡 الفكرة الأساسية

لما تحب تكتب بيانات جوه فايل، بتعمل 3 خطوات:

1. **تفتح الملف** بـ `fopen`
2. **تكتب البيانات** سواء `fprintf` أو `fwrite`
3. **تقفل الملف** بـ `fclose`

### ✔ المثال الصحيح + شرح كل سطر

```c
#include <stdio.h>

int main() {

    // WRITE A FILE 
    FILE *pFile = fopen("output.txt", "w");  
    // "w" معناها write → لو الملف مش موجود هيعمله

    char text[] = "BOOTY BOOTY BOOTY\nROCKIN' EVERYWHERE!\n";

    if (pFile == NULL) {
        printf("Error opening file\n");
        return 1;  
    }

    fprintf(pFile, "%s", text); // كتابة المحتوى داخل الملف

    printf("File was written successfully!\n");
    
    fclose(pFile); // مهم جداً

    return 0; 
}
```

---

# 📂 **ثانيًا: قراءة الملفات – Reading Files**

### 💡 الفكرة الأساسية

نفس الخطوات بس بدل الكتابة → قراءة:

1. `fopen` مع `"r"`
2. تستخدم **fgets** لقراءة سطر سطر
3. `printf` تعرض اللي اتقرأ
4. `fclose`

### ✔ مثال قراءة كامل وصحيح

```c
#include <stdio.h>

int main () {

    FILE *pFile = fopen("input.txt", "r");

    char buffer[1024] = {0};

    if (pFile == NULL) {
        printf("Couldn't open file\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), pFile) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(pFile);

    return 0;
}
```

---

# 🧠 **ثالثًا: الذاكرة الديناميكية – Dynamic Memory Allocation**

هنا بقى بنوصل للحتة اللي تفرّق بين **مبتدئ** و **مبرمج محترف**
لأنك بتتعامل مع RAM مباشرة.

---

# 🔥 **1) malloc() – أخطر Function في C**

### 📌 بتعمل إيه؟

تحجز مساحة في الميموري *من غير ما تصفّرها*.

### ❌ إصلاح الأخطاء اللي في كودك

انت كاتب:

```c
char *grades = mallco(number * sizeof(char));
free(grades);
grades = null;
if(grades == null){
    printf("Memorry allocation failed");
```

عندك 4 مشاكل:

* اسم الدالة غلط → `malloc`
* عملت `free` قبل ما تستخدم البيانات!
* كتبت `null` المفروض `NULL`
* بتشيّك على grades *بعد ما حررتها!* بدل ما تشيّك عليها بعد malloc

### ✔ الكود الصحيح + الشرح الجامد

```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int number = 0;
    printf("Enter number of grades: ");
    scanf("%d", &number);

    char *grades = malloc(number * sizeof(char));

    if (grades == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < number; i++) {
        printf("Enter grade #%d: ", i + 1);
        scanf(" %c", &grades[i]);
    }

    printf("\nGrades: ");
    for (int i = 0; i < number; i++) {
        printf("%c ", grades[i]);
    }

    free(grades);  
    grades = NULL;

    return 0;
}
```

---

# ⚪ **2) calloc() – النسخة النظيفة من malloc**

### 📌 الفرق الأساسي

* `calloc` → تحجز وتصفّر الميموري (كل bytes = 0)
* `malloc` → تحجز بس ومبتصفرش

### ✔ مثال احترافي

```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int number = 0;
    printf("Enter number of players: ");
    scanf("%d", &number);

    int *scores = calloc(number, sizeof(int));

    if (scores == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Initial scores (all zero): ");
    for (int i = 0; i < number; i++) {
        printf("%d ", scores[i]);
    }

    for (int i = 0; i < number; i++) {
        printf("\nEnter score #%d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    free(scores);
    scores = NULL;

    return 0;
}
```

---

# 🔥 **3) realloc() – ملك الذاكرة الديناميكية**

دي أقوى واحدة…
بتسمحلك **تكبّر أو تصغّر الميموري** اللي حجزتها قبل كده بدون فقد البيانات.

### 💡 مثال احترافي جدًا – Expand Array

```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int size = 3;

    int *arr = malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // أول 3 قيم
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // نكبر المصفوفة
    size = 6;
    arr = realloc(arr, size * sizeof(int));

    if (arr == NULL) {
        printf("Reallocation failed!\n");
        return 1;
    }

    // قيم جديدة
    for (int i = 3; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("\nExpanded array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
```

---

# 🎉 **ختام الجزء الخامس**

بهذا البارت انت غطّيت:

✔ كتابة الملفات
✔ قراءة الملفات
✔ malloc
✔ calloc
✔ realloc
✔ free
✔ التعامل الصح مع NULL
✔ الحالات اللي يحصل فيها memory leak

ده مستوى فعلاً يخليك جاهز تدخل على **Pointers Advance + Structures Advance + Dynamic Data Structures**.

---
