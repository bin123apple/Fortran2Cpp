program test_optional_reduction
  implicit none

  integer :: rg, rw, rv, rc

  call test_do_test()

contains

  subroutine do_test(rg, rw, rv, rc)
    integer, intent(out) :: rg, rw, rv, rc
    integer, parameter :: n = 10
    integer :: i, vresult
    integer, dimension(n) :: array

    vresult = 0
    do i = 1, n
       array(i) = i
       vresult = vresult + array(i)
    end do

    ! Initialize reduction variables
    rg = 0
    rw = 0
    rv = 0
    rc = 0

    ! Perform reductions
    do i = 1, n
       rg = rg + array(i)
    end do

    do i = 1, n
       rw = rw + array(i)
    end do

    do i = 1, n
       rv = rv + array(i)
    end do

    do i = 1, n
       rc = rc + array(i)
    end do

    if (rg /= vresult) stop 'rg failed'
    if (rw /= vresult) stop 'rw failed'
    if (rv /= vresult) stop 'rv failed'
    if (rc /= vresult) stop 'rc failed'
  end subroutine do_test

  subroutine test_do_test()
    integer :: rg, rw, rv, rc

    call do_test(rg, rw, rv, rc)

    print *, 'All tests passed.'
  end subroutine test_do_test

end program test_optional_reduction