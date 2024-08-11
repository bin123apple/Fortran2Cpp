void check(int& iresult, int ians, int& error) {
    if (iresult != ians) {
        error = error + 1;
    }
}