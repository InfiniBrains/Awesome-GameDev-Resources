// this a single line comment and it is not compiled. comments are used to explain the code.
// you can do single line comment by adding // in front of the line or
// you can do multi line comments by wrapping your comment in /* and */ such as: /* insert comment here */
/* this is
 * a multi line
 * comment
 */
#include <iostream> // this includes an external library used to deal with console input and output
#include <string> // header to deal with a char sequence, it is called string
using namespace std; // we declare that we are going to use the namespace std of the library we just included
/**
 * @brief "int" means it should return an integer number in the end of its execution to communicate if it finished properly
 * "main()" function where the operating system will look for starting the code.
 * "()" empty parameters. this main function here needs no parameter to execute
 * anynthing between { and } is considered a scope.
 * everything stack allocated in this scope will be deallocated in the end of the scope. ex.: local variables.
 * @return
 */
int main(){
     /* "cout" means console output. Print to the console the content of what is passed after the
     * "<<" stream operator. Streams what in the wright side of it to the cout object
     * "endl" means end line. Append a new line to the stream, in the case, console output.
     */
    // invites the user to write something
    cout << "Type your name: " << endl;

    /* string means the type of the variable, this definition came from the string include
     * username means the name of the variable, the container to hold and store the data
     */
    string username;
    /*
     * cin mean console input. It captures data from the console.
     * note the opposite direction of the stream operator. it streams what come from the cin object to the variable.
     */
    cin >> username;
    // example of how to stream and concatenate texts to the console output;
    cout << "Hello " << username << endl;

    /* tells the operating system the program finished without errors. Any number different from that is considered
     * a error code or error number.
     */
    return 0;
}