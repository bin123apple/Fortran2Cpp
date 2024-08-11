program test_matrix_update
  logical :: l1(2,2)
  integer :: it(2,2)
  l1(:,:) = reshape ((/.false.,.true.,.true.,.false./), (/2,2/))
  it(:,:) = reshape ((/1,2,3,4/), (/2,2/))
  forall (i = 1:2, i < 3)
    forall (j = 1:2, l1(i,j))
      it(i, j) = 0
    end forall
  end forall
  if (any (it .ne. reshape ((/1, 0, 0, 4/), (/2,2/)))) STOP 1

  ! Unit test to verify correctness
  if (all(it == reshape ((/1, 0, 0, 4/), (/2,2/)))) then
    print *, "Test passed."
  else
    print *, "Test failed."
    STOP 1
  end if
end program test_matrix_update