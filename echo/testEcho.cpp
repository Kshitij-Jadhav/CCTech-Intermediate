#include "echo.h"
#include <iostream>
#include <cassert>

int main(){
    string argv[] = {"./echo"};
    assert(echo(1, argv).str() == "\n");

    string argv2[] = {"./echo", "foo"};
    assert(echo(2, argv2).str() == "foo\n");

    string argv3[] = {"./echo", "foo", "bar"};
    assert(echo(3, argv3).str() == "foo bar\n");

    string argv4[] = {"./echo", "foo    bar"};
    assert(echo(2, argv4).str() == "foo    bar\n");
    
    return EXIT_SUCCESS;
}