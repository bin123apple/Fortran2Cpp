program simulate_parallel
    implicit none
    integer, parameter :: num_nodes = 4
    integer :: me, i, n1, n2, n3
    integer, dimension(20, num_nodes) :: a

    ! Simulate different nodes by iterating and assigning values as if within different processes
    do me = 1, num_nodes
        do i = 1, 20
            a(i, me) = i * me
        end do
    end do

    ! Simulate fetching values from different "nodes"
    ! Note: This is purely illustrative and does not represent actual parallel or distributed computing
    n1 = a(10, 1)
    n2 = a(10, 2)
    n3 = a(10, 3)

    ! Output the simulated results
    do me = 1, num_nodes
        write(*,*) "me,n1,n2,n3=", me, n1, n2, n3
    end do
end program simulate_parallel