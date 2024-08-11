! test_book.f90
program test_book
    implicit none
    type book
        character(len=40) :: title
        character(len=40) :: author
        integer           :: year
        integer           :: ID
        character(len=40) :: publisher
    end type book

    type(book) :: book1

    book1%title     = "World"
    book1%author    = "Me"
    book1%year      = 1985
    book1%ID        = 12
    book1%publisher = "Venezia"

    call test_book1(book1)

contains

    subroutine test_book1(b)
        type(book), intent(in) :: b

        if (b%title /= "World") stop "Test Failed: Title mismatch"
        if (b%author /= "Me") stop "Test Failed: Author mismatch"
        if (b%year /= 1985) stop "Test Failed: Year mismatch"
        if (b%ID /= 12) stop "Test Failed: ID mismatch"
        if (b%publisher /= "Venezia") stop "Test Failed: Publisher mismatch"

        print *, "All tests passed for book1"
    end subroutine test_book1

end program test_book