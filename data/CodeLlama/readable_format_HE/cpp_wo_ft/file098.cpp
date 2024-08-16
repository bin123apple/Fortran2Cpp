[INST] Translate this Fortran code to C++: 
program collatz
  implicit none
  integer, allocatable :: result(:)
  integer :: n

  ! Test cases
  call test_odd_collatz(14, [1, 5, 7, 11, 13, 17])
  call test_odd_collatz(5, [1, 5])
  call test_odd_collatz(12, [1, 3, 5])
  call test_odd_collatz(1, [1])

contains

  subroutine test_odd_collatz(n, expected)
    integer, intent(in) :: n
    integer, dimension(:), intent(in) :: expected
    integer, allocatable :: result(:)
    logical :: is_same

    result = get_odd_collatz(n)
    is_same = issame(result, expected)
    if (.not. is_same) then
      write(*,*) "Assertion failed for n =", n
      call exit(1)
    end if
  end subroutine test_odd_collatz

  function get_odd_collatz(n) result(out)
    integer, intent(in) :: n
    integer, allocatable :: out(:)
    integer :: temp, i, count
    integer, allocatable :: temp_array(:)

    allocate(out(1))
    out(1) = 1
    temp = n
    count = 1

    do while (temp /= 1)
      if (mod(temp, 2) == 1) then
        count = count + 1
        if (allocated(temp_array)) deallocate(temp_array)
        allocate(temp_array(count))
        temp_array(1:count-1) = out
        temp_array(count) = temp
        deallocate(out)
        out = temp_array
        temp = temp * 3 + 1
      else
        temp = temp / 2
      end if
    end do

    call sort(out)
  end function get_odd_collatz

  function issame(a, b) result(is_equal)
    integer, dimension(:), intent(in) :: a, b
    logical :: is_equal
    integer :: i

    if (size(a) /= size(b)) then
      is_equal = .false.
      return
    end if

    is_equal = .true.
    do i = 1, size(a)
      if (a(i) /= b(i)) then
        is_equal = .false.
        return
      end if
    end do
  end function issame

  subroutine sort(array)
    integer, dimension(:), intent(inout) :: array
    integer :: i, j, temp

    do i = 1, size(array) - 1
      do j = i + 1, size(array)
        if (array(i) > array(j)) then
          temp = array(i)
          array(i) = array(j)
          array(j) = temp
        end if
      end do
    end do
  end subroutine sort

end program collatz [/INST]

[INST] Translate this Fortran code to C++: 
program collatz
  implicit none
  integer, allocatable :: result(:)
  integer :: n

  ! Test cases
  call test_odd_collatz(14, [1, 5, 7, 11, 13, 17])
  call test_odd_collatz(5, [1, 5])
  call test_odd_collatz(12, [1, 3, 5])
  call test_odd_collatz(1, [1])

contains

  subroutine test_odd_collatz(n, expected)
    integer, intent(in) :: n
    integer, dimension(:), intent(in) :: expected
    integer, allocatable :: result(:)
    logical :: is_same

    result = get_odd_collatz(n)
    is_same = issame(result, expected)
    if (.not. is_same) then
      write(*,*) "Assertion failed for n =", n
      call exit(1)
    end if
  end subroutine test_odd_collatz

  function get_odd_collatz(n) result(out)
    integer, intent(in) :: n
    integer, allocatable :: out(:)
    integer :: temp, i, count
    integer, allocatable :: temp_array(:)

    allocate(out(1))
    out(1) = 1
    temp = n
    count = 1

    do while (temp /= 1)
      if (mod(temp, 2) == 1) then
        count = count + 1
        if (allocated(temp_array)) deallocate(temp_array)
        allocate(temp_array(count))
        temp_array(1:count-1) = out
        temp_array(count) = temp
        deallocate(out)
        out = temp_array
        temp = temp * 3 + 1
      else
        temp = temp / 2
      end if
    end do

    call sort(out)
  end function get_odd_collatz

  function issame(a, b) result(is_equal)
    integer, dimension(:), intent(in) :: a, b
    logical :: is_equal
    integer :: i

    if (size(a) /= size(b)) then
      is_equal = .false.
      return
    end if

    is_equal = .true.
    do i = 1, size(a)
      if (a(i) /= b(i)) then
        is_equal = .false.
        return
      end if
    end do
  end function issame

  subroutine sort(array)
    integer, dimension(:), intent(inout) :: array
    integer :: i, j, temp

    do i = 1, size(array) - 1
      do j = i + 1, size(array)
        if (array(i) > array(j)) then
          temp = array(i)
          array(i) = array(j)
          array(j) = temp
        end if
      end do
    end do
  end subroutine sort

end program collatz [/INST]

[INST] Translate this Fortran code to C++: 
program collatz
  implicit none
  integer, allocatable :: result(:)
  integer :: n

  ! Test cases
  call test_odd_collatz(14, [1, 5, 7, 11, 13, 17])
  call test_odd_collatz(5, [1, 5])
  call test_odd_collatz(12, [1, 3, 5])
  call test_odd_collatz(1, [1])

contains

  subroutine test_odd_collatz(n, expected)
    integer, intent(in) :: n
    integer, dimension(:), intent(in) :: expected
    integer, allocatable :: result(:)
    logical :: is_same

    result = get_odd_collatz(n)
    is_same = issame(result, expected)
    if (.not. is_same) then
      write(*,*) "Assertion failed for n =", n
      call exit(1)
    end if
  end subroutine test_odd_collatz

  function get_odd_collatz(n) result(out)
    integer, intent(in) :: n
    integer, allocatable :: out(:)
    integer :: temp, i, count
    integer, allocatable :: temp_array(:)

    allocate(out(1))
    out(1) = 1
    temp = n
    count = 1

    do while (temp /= 1)
      if (mod(temp, 2) == 1) then
        count = count + 1
        if (allocated(temp_array)) deallocate(temp_array)
        allocate(temp_array(count))
        temp_array(1:count-1) = out
        temp_array(count) = temp
        deallocate(out)
        out = temp_array
        temp = temp * 3 + 1
      else
        temp = temp / 2
      end
