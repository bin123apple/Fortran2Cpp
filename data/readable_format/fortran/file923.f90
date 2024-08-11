program p
    integer :: x = 10
    associate(y => x)
        print *, "The value of y is: ", y
    end associate
end program p