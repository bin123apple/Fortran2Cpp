#include <cstdlib>
#include <iostream>
#include <string>

bool same_chars(const std::string &s0, const std::string &s1) {
    for (size_t i = 0; i < s0.size(); ++i) {
        if (s1.find(s0[i]) == std::string::npos) {
            return false;
        }
    }

    for (size_t i = 0; i < s1.size(); ++i) {
        if (s0.find(s1[i]) == std::string::npos) {
            return false;
        }
    }

    return true;
}

int main() {
    if (!same_chars("eabcdzzzz", "dddzzzzzzzddeddabc")) {
        std::cerr << "Assertion failed: same_chars("eabcdzzzz", "dddzzzzzzzddeddabc") == true" << std::endl;
        std::exit(1);
    }

    if (!same_chars("abcd", "dddddddabc")) {
        std::cerr << "Assertion failed: same_chars("abcd", "dddddddabc") == true" << std::endl;
        std::exit(1);
    }

    if (!same_chars("dddddddabc", "abcd")) {
        std::cerr << "Assertion failed: same_chars("dddddddabc", "abcd") == true" << std::endl;
        std::exit(1);
    }

    if (same_chars("eabcd", "dddddddabc")) {
        std::cerr << "Assertion failed: same_chars("eabcd", "dddddddabc") == false" << std::endl;
        std::exit(1);
    }

    if (same_chars("abcd", "dddddddabcf")) {
        std::cerr << "Assertion failed: same_chars("abcd", "dddddddabcf") == false" << std::endl;
        std::exit(1);
    }

    if (same_chars("eabcdzzzz", "dddzzzzzzzddddabc")) {
        std::cerr << "Assertion failed: same_chars("eabcdzzzz", "dddzzzzzzzddddabc") == false" << std::endl;
        std::exit(1);
    }

    if (same_chars("aabb", "aaccc")) {
        std::cerr << "Assertion failed: same_chars("aabb", "aaccc") == false" << std::endl;
        std::exit(1);
    }

    std::cout << "All assertions passed." << std::endl;
}

[Fortran]
program main
    implicit none
    logical :: result

    ! Declare the function interface
    interface
        logical function same_chars(s0, s1)
            character(len=*), intent(in) :: s0, s1
        end function same_chars
    end interface

    result = same_chars("eabcdzzzz", "dddzzzzzzzddeddabc")
    if (.not. result) then
        write(*,*) "Assertion failed: same_chars('eabcdzzzz', 'dddzzzzzzzddeddabc') == true"
        call exit(1)
    end if

    result = same_chars("abcd", "dddddddabc")
    if (.not. result) then
        write(*,*) "Assertion failed: same_chars('abcd', 'dddddddabc') == true"
        call exit(1)
    end if

    result = same_chars("dddddddabc", "abcd")
    if (.not. result) then
        write(*,*) "Assertion failed: same_chars('dddddddabc', 'abcd') == true"
        call exit(1)
    end if

    result = same_chars("eabcd", "dddddddabc")
    if (result) then
        write(*,*) "Assertion failed: same_chars('eabcd', 'dddddddabc') == false"
        call exit(1)
    end if

    result = same_chars("abcd", "dddddddabcf")
    if (result) then
        write(*,*) "Assertion failed: same_chars('abcd', 'dddddddabcf') == false"
        call exit(1)
    end if

    result = same_chars("eabcdzzzz", "dddzzzzzzzddddabc")
    if (result) then
        write(*,*) "Assertion failed: same_chars('eabcdzzzz', 'dddzzzzzzzddddabc') == false"
        call exit(1)
    end if

    result = same_chars("aabb", "aaccc")
    if (result) then
        write(*,*) "Assertion failed: same_chars('aabb', 'aaccc') == false"
        call exit(1)
    end if

    write(*,*) "All assertions passed."
end program main

logical function same_chars(s0, s1)
    implicit none
    character(len=*), intent(in) :: s0, s1
    integer :: i

    do i = 1, len_trim(s0)
        if (index(s1, s0(i:i)) == 0) then
            same_chars = .false.
            return
        end if
    end do

    do i = 1, len_trim(s1)
        if (index(s0, s1(i:i)) == 0) then
            same_chars = .false.
            return
        end if
    end do

    same_chars = .true.
end function same_chars [/Fortran]

[C]
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool same_chars(const char *s0, const char *s1) {
    size_t i;

    for (i = 0; i < strlen(s0); ++i) {
        if (strchr(s1, s0[i]) == NULL) {
            return false;
        }
    }

    for (i = 0; i < strlen(s1); ++i) {
        if (strchr(s0, s1[i]) == NULL) {
            return false;
        }
    }

    return true;
}

int main() {
    if (!same_chars("eabcdzzzz", "dddzzzzzzzddeddabc")) {
        fprintf(stderr, "Assertion failed: same_chars("eabcdzzzz", "dddzzzzzzzddeddabc") == true
");
        exit(1);
    }

    if (!same_chars("abcd", "dddddddabc")) {
        fprintf(stderr, "Assertion failed: same_chars("abcd", "dddddddabc") == true
");
        exit(1);
    }

    if (!same_chars("dddddddabc", "abcd")) {
        fprintf(stderr, "Assertion failed: same_chars("dddddddabc", "abcd") == true
");
        exit(1);
    }

    if (same_chars("eabcd", "dddddddabc")) {
        fprintf(stderr, "Assertion failed: same_chars("eabcd", "dddddddabc") == false
");
        exit(1);
    }

    if (same_chars("abcd", "dddddddabcf")) {
        fprintf(stderr, "Assertion failed: same_chars("abcd", "dddddddabcf") == false
");
        exit(1);
    }

    if (same_chars("eabcdzzzz", "dddzzzzzzzddddabc")) {
        fprintf(stderr, "
