! Define the subroutine networkinum
subroutine networkinum(ipkon, inum, kon, lakon, ne, itg, ntg, network)
  implicit none

  character(len=8) :: lakon(*)
  integer :: ipkon(*), inum(*), kon(*), ne, itg(*), ntg, network
  integer :: i, node1, node2, node3, indexe
  character(len=8) :: lakonl

  do i=1,ntg
     if (inum(itg(i)) > 0) inum(itg(i)) = -inum(itg(i))
  end do

  do i=1,ne
     if (ipkon(i) < 0) cycle
     lakonl = lakon(i)
     if ((lakonl(1:1) /= 'D') .and. ((lakonl(1:1) /= 'D') .or. (network /= 1))) cycle

     indexe = ipkon(i)
     if (kon(indexe+1) /= 0) then
        node1 = kon(indexe+1)
        if (inum(node1) > 0) inum(node1) = -inum(node1)
     end if
     node2 = kon(indexe+2)
     if (inum(node2) > 0) inum(node2) = -inum(node2)
     if (kon(indexe+3) /= 0) then
        node3 = kon(indexe+3)
        if (inum(node3) > 0) inum(node3) = -inum(node3)
     end if
  end do
end subroutine networkinum

! Main program to test the subroutine
program test_networkinum
  implicit none

  integer, parameter :: ne=2, ntg=2
  integer :: ipkon(ne), inum(ne), kon(6), itg(ntg), network
  character(len=8) :: lakon(ne)

  ! Initialize test data
  network = 1
  ipkon = (/ 1, 4 /)
  inum = (/ 2, -3 /)
  kon = (/ 1, 2, 0, 2, 3, 0 /)
  itg = (/ 1, 2 /)
  lakon = (/'D0000001', 'D0000002'/)

  ! Call the subroutine
  call networkinum(ipkon, inum, kon, lakon, ne, itg, ntg, network)

  ! Output the results for checking
  print *, "Modified inum:", inum

end program test_networkinum