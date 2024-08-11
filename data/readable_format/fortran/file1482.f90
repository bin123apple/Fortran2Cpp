program collapse2_tests
  implicit none

  call test_test1
  call test_test2

contains

  subroutine test1
    integer :: i, j, k, a(1:3, 4:6, 5:7)
    logical :: l
    l = .false.
    a(:, :, :) = 0
    !$acc parallel reduction(.or.:l)
    !$acc loop worker vector collapse(4 - 1)
    do 164 i = 1, 3
      do 164 j = 4, 6
        do 164 k = 5, 7
          a(i, j, k) = i + j + k
164     end do
    !$acc loop worker vector reduction(.or.:l) collapse(2)
firstdo: do i = 1, 3
          do j = 4, 6
            do k = 5, 7
              if (a(i, j, k) .ne. (i + j + k)) l = .true.
            end do
          end do
        end do firstdo
    !$acc end parallel
    if (l) call abort
    print *, "test1 passed."
  end subroutine test1

  subroutine test2
    integer :: a(3,3,3), k, kk, kkk, l, ll, lll
    a = 0
    !$acc parallel num_workers(8)
    !$acc loop gang(static:1) collapse(1)
    do 115 k=1,3
       !$acc loop collapse(2)
dokk:  do kk=1,3
          do kkk=1,3
            a(k,kk,kkk) = 1
          end do
        end do dokk
115   continue
    !$acc loop gang(static:1) collapse(1)
    do k=1,3
       if (any(a(k,1:3,1:3).ne.1)) call abort
    end do
    !$acc loop gang(static:1) collapse(1)
dol:  do 120 l=1,3
      !$acc loop collapse(2)
doll:   do ll=1,3
          do lll=1,3
            a(l,ll,lll) = 2
          end do
        end do doll
120   end do dol
    !$acc loop gang(static:1) collapse(1)
    do l=1,3
       if (any(a(l,1:3,1:3).ne.2)) call abort
    end do
    !$acc end parallel
    print *, "test2 passed."
  end subroutine test2

  subroutine test_test1
    call test1
  end subroutine test_test1

  subroutine test_test2
    call test2
  end subroutine test_test2

end program collapse2_tests