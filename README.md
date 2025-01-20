NOTE: Admin Password is 1234

**Student Registration & Grading System**

A simple C++ program designed to handle student registration, grading, and the management of student information. The system allows for admin authentication, student registration, grade input, and viewing of student grades and information based on a CSV file system.


**Features**

1.	Admin Authentication: Admins can authenticate with a password to perform sensitive operations like registration and grading.


2. Student Registration: Register new students with essential details (ID, name, father's name, age, sex, etc.) and generate a unique password for them.

3. Student Grading: Admins can enter grades for students based on assessments and finals, which are then used to calculate SGPA.

4. View Student Info: Students can view their own registered information using their ID and password.

5. Section-based Viewing: Admins can view the grades of all students in a particular section.
   
**Prerequisites**

•	C++ Compiler (e.g., GCC, Clang)
•	Required CSV files located in the resources.ZIP file or the GitHub repository.

**Installation**

1.	Clone or download the project from GitHub.
2.	Ensure that the required CSV files (section-A.csv, section-B.csv) are placed in the project folder (you can find these in resources.ZIP or the repository).
3.	Open the project in your preferred C++ IDE or use a terminal to compile.

**Usage**

Once the program is compiled and running, you can choose from the following options:

1.	Register a New Student: Allows the admin to register new students by providing essential details.
2.	Enter Marks and Calculate SGPA: Admins can input final and assessment marks to grade students and calculate their SGPA.
3.	Show Grade by Section: Admins can view the grade of all students in a specific section (A or B).
4.	Show Student Info: Students can view their personal information using their student ID and password.
5.	Exit: Exits the program.


**CSV File Format**

Each section (A, B) CSV file should follow this format:
ID,Password,Name,Father's Name,Age,Sex,Fop,Intro,Discrete,History,Global Trend,P&S,SGPA
Where:

•	ID: Unique student identifier

•	Password: Generated PIN for student access

•	Name: Full name of the student

•	Father's Name: Father's name

•	Age: Age of the student

•	Sex: Gender of the student

•	Fop, Intro, Discrete, History, Global Trend, P&S: Marks or course codes

•	SGPA: Cumulative grade point average (to be calculated)

**Admin Password**

The default admin password is 1234. Modify the preset variable if you wish to change this.


**Contact**

If you have any questions or issues, feel free to open an issue in the GitHub repository.

