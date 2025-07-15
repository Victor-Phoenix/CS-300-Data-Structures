# CS-300 Portfolio Submission

## 📌 Project Overview
This repository contains selected portions of **Project One** and **Project Two** from CS-300. These projects demonstrate my understanding of **data structures, algorithms, and efficient program design**.

- **Project One:** Includes the analysis of **runtime and memory usage** for different data structures.
- **Project Two:** Includes the **C++ code that sorts and prints course information in alphanumeric order**.

Together, these documents showcase my skills in **data structures, efficiency analysis, and algorithm design**.

---

## 📌 Reflection on CS-300 Projects

### **What was the problem you were solving in the projects for this course?**
The primary goal was to develop an **Advising Assistance Program** that allows users to **load, store, sort, and retrieve course information efficiently**. The program needed to support:
1. **Loading course data from a file**
2. **Sorting courses in alphanumeric order**
3. **Retrieving course details and prerequisites efficiently**

### **How did you approach the problem?**
To ensure **efficient storage and retrieval**, I evaluated multiple **data structures**:
- **Vectors** for simple sequential access.
- **Binary Search Trees (BSTs)** for ordered retrieval.
- **Hash Tables** for fast lookup times.

After analyzing **runtime complexity (Big O)**, I selected the **Hash Table** for storing courses due to its **O(1) average-time complexity for lookups**, making it ideal for quick retrieval.

### **How did you overcome roadblocks during the project?**
One major challenge was handling **file input errors and directory paths**. Initially, the program could not locate the CSV file. I solved this by:
- Debugging **working directory issues**.
- Using **absolute file paths** during testing.
- Implementing **error handling** to guide users when a file is missing.

Additionally, ensuring that **course data was correctly parsed** (handling prerequisites with variable lengths) was another hurdle. I solved this by **using string streams to handle comma-separated values dynamically**.

### **How has this project expanded your approach to software design?**
This project reinforced the importance of **choosing the right data structure for a given problem**. It also highlighted the value of:
- **Modular programming** (keeping functions independent and reusable).
- **Error handling** to make programs more robust.
- **User-friendly design** (providing clear prompts and preventing incorrect input).

### **How has this project improved your ability to write maintainable, readable, and adaptable code?**
Before this project, I would often write **code that worked but was not structured well**. This project helped me:
1. **Improve code readability** by adding **comments** and **clear function names**.
2. **Use consistent formatting** for easy maintenance.
3. **Implement error handling** to make the program more adaptable to real-world use cases.
4. **Think ahead about scalability**, ensuring that if more courses were added, the system would still perform efficiently.


---

## 📌 **Files in This Repository**
| **File**                  | **Description** |
|---------------------------|----------------|
| `runtime_analysis.pdf`    | **Project One**: Big O runtime & memory analysis |
| `ProjectTwo.cpp`          | **Project Two**: C++ code for sorting & printing courses |
| `README.md`               | Reflection on projects |
