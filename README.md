# Sorting Algorithms System
This project demonstrates the implementation and performance comparison of **four classic sorting algorithms**:  
- **Merge Sort**
- **Quick Sort**
- **Bubble Sort**
- **Shell Sort**

The program generates a set of unique random integers, stores them in text files, allows the user to select a sorting algorithm, and then outputs the sorted list along with the **execution time**.

---

## 🛠 Features
✅ Generates 100, 200, or 300 unique integers using a random seed (Matric ID `191020976`).  
✅ Saves generated numbers into `100data.txt`, `200data.txt`, `300data.txt`.  
✅ Allows users to choose between four sorting algorithms.  
✅ Displays unsorted and sorted arrays.  
✅ Measures and displays execution time for each algorithm.  
✅ Handles invalid input gracefully with error messages.  
✅ Simple text-based menu navigation.  

---

## 📊 Algorithm Performance
| **Number of Integers** | **Merge Sort (ms)** | **Quick Sort (ms)** | **Bubble Sort (ms)** | **Shell Sort (ms)** |
|------------------------|---------------------|---------------------|----------------------|---------------------|
| 100                    | 0.080               | 0.071               | 0.109                | 0.090               |
| 200                    | 0.156               | 0.157               | 0.172                | 0.184               |
| 300                    | 0.203               | 0.242               | 0.253                | 0.268               |
📌 **Observation:** Quick Sort performs fastest for small data sets (≤ 300 elements), while Merge Sort may outperform Quick Sort for much larger data sets due to its stability and guaranteed O(n log n) complexity.

---

⚠️ Limitations

The program does not save sorted results to a separate file (only displays them). Execution time may vary slightly between runs due to system load and randomness.

---

💡 Suggested Enhancements
- Save Sorted Data – Write the sorted arrays into new text files (e.g., sorted_100data.txt).
- Consistent Timing – Use a more precise time measurement library for reproducible timing results.
- Scalability Testing – Add support for larger data sets (e.g., 10,000+ integers) to observe performance trends.
- Algorithm Visualization – Implement step-by-step visualization of sorting (helpful for learning).
- Unit Testing – Include automated tests for each sorting function to ensure correctness.

---

📜 License

This project is for educational purposes under EKT 224 – Algorithm and Data Structures coursework.
You may modify and use this project for learning, but proper credit to the author is appreciated.
