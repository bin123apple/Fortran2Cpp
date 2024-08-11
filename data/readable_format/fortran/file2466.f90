program test_ds2hms
  implicit none

  double precision secs, ss
  integer hh, mm

  ! Test cases
  call testProcedure

contains

  subroutine ds2hms(secs, hh, mm, ss)
    implicit none

    double precision secs, ss
    integer hh, mm

    double precision s2h, s2m
    parameter (s2h = (1.d0 / 3600.d0), s2m = (1.d0 / 60.d0))

    double precision s
    integer h, m

    s = secs
    h = s * s2h
    s = -(3600 * h) + s
    m = s * s2m
    s = -(60 * m) + s

    hh = h
    mm = m
    ss = s

  end subroutine ds2hms

  subroutine testProcedure
    implicit none

    ! Test case 1
    secs = 3661.0
    call ds2hms(secs, hh, mm, ss)
    print *, "Test case 1: "
    print *, "Expected: 1, 1, 1.0"
    print *, "Actual: ", hh, mm, ss
    print *, "------------------------"

    ! Test case 2
    secs = 7322.0
    call ds2hms(secs, hh, mm, ss)
    print *, "Test case 2: "
    print *, "Expected: 2, 2, 2.0"
    print *, "Actual: ", hh, mm, ss
    print *, "------------------------"

    ! Test case 3
    secs = 59.0
    call ds2hms(secs, hh, mm, ss)
    print *, "Test case 3: "
    print *, "Expected: 0, 0, 59.0"
    print *, "Actual: ", hh, mm, ss
    print *, "------------------------"

    ! Test case 4
    secs = 3600.0
    call ds2hms(secs, hh, mm, ss)
    print *, "Test case 4: "
    print *, "Expected: 1, 0, 0.0"
    print *, "Actual: ", hh, mm, ss
    print *, "------------------------"

    ! Test case 5
    secs = 0.0
    call ds2hms(secs, hh, mm, ss)
    print *, "Test case 5: "
    print *, "Expected: 0, 0, 0.0"
    print *, "Actual: ", hh, mm, ss
    print *, "------------------------"

  end subroutine testProcedure

end program test_ds2hms