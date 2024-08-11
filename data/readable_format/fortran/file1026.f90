program get1
    implicit none
    integer :: i
    type :: g1
       integer(8) :: a(3)
       real(8) :: r(3)
    end type g1

    type(g1) :: s1, s2
    integer :: me = 2 ! Simulate process 2
    
    ! Initialize s1
    do i = 1, 3
        s1%a(i) = i * 3 ! Simulate values from process 3
        s1%r(i) = 1.0 / i / 3
    end do
    
    ! Simulate receiving s1 into s2 on process 2
    if (me == 2) then
        s2 = s1
    end if
    
    ! Output for verification
    do i = 1, 3
        print *, "s2%a(", i, ") = ", s2%a(i), ", s2%r(", i, ") = ", s2%r(i)
    end do
end program get1