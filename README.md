# Pass Breaker
Pass Breaker is a simple password cracking tool that supports both **brute force** and **dictionary attacks**. It is implemented in C++ and allows users to test password strength by attempting to guess the target password using different attack methods.

## Features
- **Brute Force Attack**: Tries all possible character combinations up to a given length.
- **Dictionary Attack**: Reads passwords from a dictionary file and attempts to match them.
- **Custom Character Set Support**: Users can define the characters to be used in brute force mode.
- **Execution Time Measurement**: Displays the time taken for each attack.

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/PassBreaker.git
   ```
2. Navigate to the project folder:
   ```sh
   cd PassBreaker
   ```
3. Compile the program using a C++ compiler (e.g., g++):
   ```sh
   g++ pass_breaker.cpp -o pass_breaker
   ```

## Usage
Run the compiled executable:
```sh
./pass_breaker
```
Follow the on-screen instructions to:
1. Enter the target password.
2. Choose an attack method:
   - **Brute Force Attack**: Enter the character set and maximum password length.
   - **Dictionary Attack**: Provide the dictionary file path.
3. View the results, including the cracked password (if found) and time taken.

### Example
#### **Brute Force Attack**
```
Enter the target password: 1234
Choose an attack method:
1. Brute Force Attack
2. Dictionary Attack
Enter your choice: 1
Enter the character set to use (e.g., abc123): 0123456789
Enter the maximum password length to try: 4
Password cracked: 1234
Time taken: 0.01 sec.
```

#### **Dictionary Attack**
```
Enter the target password: hello123
Choose an attack method:
1. Brute Force Attack
2. Dictionary Attack
Enter your choice: 2
Enter the dictionary file path: passwords.txt
Trying pass: password
Trying pass: 123456
Trying pass: hello123
Password cracked: hello123
Time taken: 0.002 sec.
```

## Dictionary File Format
The dictionary file should contain one password per line, for example:
```
password
123456
hello123
qwerty
letmein
admin
```

## Disclaimer
This tool is for **educational and security testing purposes only**. Unauthorized password cracking or hacking is illegal. Use this tool only on passwords you have permission to test.

## License
This project is open-source and available under the MIT License.

## Contributing
Contributions are welcome! Feel free to fork the repository and submit pull requests.

## Author
Developed by **Harsh Arora**.
