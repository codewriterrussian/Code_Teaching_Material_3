
# Code Teaching Material 3



This directory contains the third set of Python teaching materials.



## Directory Structure



- `notebooks/`

  - Student lesson notebooks.



- `notebooks_solution_teacher_only/`

  - Teacher solutions and completed notebooks.

  - Do not distribute this directory to students.



- `student_handouts_md/`

  - Markdown student handouts.

  - Lesson images are stored in `student_handouts_md/images/`.



- `exercises/`

  - Additional Python exercises and practice files.



- `tests/`

  - Test scripts and automatic checking programs.



- `tools/`

  - Scripts used to prepare, validate, or maintain teaching materials.



## Naming Convention



### Lesson notebooks



```text

lesson_01.ipynb

lesson_02.ipynb

lesson_03.ipynb

````



### Student handouts



```text

Lesson_01_Topic_Name.md

Lesson_02_Topic_Name.md

```



### Teacher solutions



```text

lesson_01_solution.ipynb

lesson_02_solution.ipynb

```



### Tests



```text

test_lesson_01.py

test_lesson_02.py

```



## Student Files



Files that may be distributed to students:



* `notebooks/`

* `student_handouts_md/`

* `exercises/`



## Teacher-Only Files



The following directory should not be distributed to students:



* `notebooks_solution_teacher_only/`

  EOF



````



The last `EOF` must:



- appear alone on its own line

- have no spaces before or after it

- not be placed inside Markdown backticks in Terminal



Then create the handout README:



```bash

cat > Code_Teaching_Material_3/student_handouts_md/README.md <<'EOF'

# Student Handouts



This directory contains Markdown handouts for students.



## File Naming



```text

Lesson_01_Topic_Name.md

Lesson_02_Topic_Name.md

````



## Images



Place images in lesson-specific directories:



```text

images/

└── Lesson_01_Topic_Name/

    ├── Lesson_01_Topic_Name_img1.png

    └── Lesson_01_Topic_Name_img2.png

```



Reference an image from a Markdown handout with:



```markdown

![Description](images/Lesson_01_Topic_Name/Lesson_01_Topic_Name_img1.png)

```



