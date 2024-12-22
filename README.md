# **Process-Based Calculator**  

## **Project Description**  
A process-based calculator application implemented in C that uses Inter-Process Communication (IPC) via pipes. 
The program performs addition, subtraction, multiplication, and division using child processes (`fork`, `exec`) for each operation. Results are saved to a file using an external `saver` program.  

This project demonstrates system-level programming concepts and how processes communicate effectively in a UNIX-like environment.  

---

## **Features**  
- **Mathematical Operations**: Addition, subtraction, multiplication, and division.  
- **Process Management**: Uses `fork` to create child processes and `exec` to execute operations.  
- **Inter-Process Communication**: Data is transferred between processes using pipes.  
- **Result Saving**: Outputs are saved to a text file via a separate saver program.  

---

## **How It Works**  
1. **Main Program**: Displays a menu to the user and spawns child processes to handle calculations.  
2. **Child Processes**: Each operation (e.g., addition) is executed by a separate child process using `exec`.  
3. **Pipes**: Used to send the results from child processes back to the main program.  
4. **Saver Program**: Results are passed as arguments to the `saver` program, which writes them to a file.  

---

## **Usage**  

### **Compile**  
Run the following command to compile all source files:  
```bash
make
```  

### **Run**  
To start the calculator:  
```bash
./calculator
```  

### **Example Output**  
```
Calculator  
1- Addition  
2- Subtraction  
3- Multiplication  
4- Division  
5- Exit  
Choose an option: 1  
Enter two numbers (num1 num2): 12 34  
Result: 46  

Choose an option: 5  
Exiting...
```  



## **Project Structure**  
```plaintext
.
├── calculator.c       # Main program
├── addition.c         # Handles addition
├── subtraction.c      # Handles subtraction
├── multiplication.c   # Handles multiplication
├── division.c         # Handles division
├── saver.c            # Saves results to a file
├── Makefile           # Compilation rules
└── results.txt        # Output file for results
