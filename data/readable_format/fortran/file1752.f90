program testcloc
    use, intrinsic :: iso_c_binding
    implicit none

    type obj
        real :: array(10,10)
        real, allocatable :: array2(:,:)
    end type

    type(obj), target :: obj1
    type(c_ptr) :: cptr
    integer :: i
    real, pointer :: array(:)

    allocate (obj1%array2(10,10))
    obj1%array  = reshape ([(i, i=1,100)], shape (obj1%array))
    obj1%array2 = reshape ([(i, i=1,100)], shape (obj1%array2))

    cptr = c_loc (obj1%array)
    call c_f_pointer (cptr, array, shape=[100])
    if (any (array /= [(i, i=1,100)])) then
        print *, "Test failed for obj1%array"
    else
        print *, "Test passed for obj1%array"
    end if

    cptr = c_loc (obj1%array2)
    call c_f_pointer (cptr, array, shape=[100])
    if (any (array /= [(i, i=1,100)])) then
        print *, "Test failed for obj1%array2"
    else
        print *, "Test passed for obj1%array2"
    end if
end program testcloc