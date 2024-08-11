program test_indexx
  implicit none
  integer, allocatable :: indx(:)
  double precision, allocatable :: arrin(:)
  integer :: N, i

  ! Test 1: Empty array
  N = 0
  allocate(arrin(N), indx(N))
  call indexx(N, arrin, indx)
  print *, 'Test 1: Empty array - Passed if no error'

  ! Test 2: Array with unique elements
  N = 5
  allocate(arrin(N), indx(N))
  arrin = (/1.0, 5.0, 3.0, 4.0, 2.0/)
  call indexx(N, arrin, indx)
  print *, 'Test 2: Array with unique elements: ', indx

  ! Test 3: Array with repeated elements
  N = 6
  allocate(arrin(N), indx(N))
  arrin = (/2.0, 1.0, 2.0, 3.0, 3.0, 1.0/)
  call indexx(N, arrin, indx)
  print *, 'Test 3: Array with repeated elements: ', indx

  deallocate(arrin, indx)

contains

  subroutine indexx(N, arrin, indx)
    integer, intent(in) :: N
    double precision, dimension(N), intent(in) :: arrin
    integer, dimension(N), intent(out) :: indx
    integer :: L, IR, J, INDXT, I
    double precision :: Q

    do I = 1, N
      indx(I) = I
    end do

    if (N < 1) return

    L = N / 2 + 1
    IR = N

    do while (.true.)
      if (L > 1) then
        L = L - 1
        INDXT = indx(L)
        Q = arrin(INDXT)
      else
        INDXT = indx(IR)
        Q = arrin(INDXT)
        indx(IR) = indx(1)
        IR = IR - 1
        if (IR == 1) then
          indx(1) = INDXT
          return
        endif
      endif

      I = L
      J = 2 * L

      do while (J <= IR)
        if (J < IR) then
          if (arrin(indx(J)) < arrin(indx(J+1))) J = J + 1
        endif
        if (Q < arrin(indx(J))) then
          indx(I) = indx(J)
          I = J
          J = 2 * J
        else
          exit
        endif
      end do

      indx(I) = INDXT
    end do
  end subroutine indexx

end program test_indexx