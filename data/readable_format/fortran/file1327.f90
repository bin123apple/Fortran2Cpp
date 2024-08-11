! test_ambervar.f90
module ambervar
    implicit none
    character(len=:), allocatable :: mmdir
    character(len=:), allocatable :: qmdir
    character(len=:), allocatable :: qmbase
    character(len=:), allocatable :: mmbase
end module ambervar

program test_ambervar
    use ambervar
    implicit none

    ! Set values
    mmdir = "test_mmdir"
    qmdir = "test_qmdir"
    qmbase = "test_qmbase"
    mmbase = "test_mmbase"

    ! Test values
    if (mmdir /= "test_mmdir") stop "Test failed for mmdir"
    if (qmdir /= "test_qmdir") stop "Test failed for qmdir"
    if (qmbase /= "test_qmbase") stop "Test failed for qmbase"
    if (mmbase /= "test_mmbase") stop "Test failed for mmbase"

    print *, "All tests passed."
end program test_ambervar