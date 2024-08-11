module deque_mod
  implicit none

  type, abstract :: deque
  contains
    procedure(push_int_sub), deferred :: pushleft
    procedure(push_int_sub), deferred :: pushright
    procedure(pop_int_func), deferred :: popleft
    procedure(pop_int_func), deferred :: popright
    procedure(peek_int_func), deferred :: peekleft
    procedure(peek_int_func), deferred :: peekright
  end type deque

  abstract interface
    subroutine push_int_sub(this, item)
      import :: deque
      class(deque), intent(inout) :: this
      integer, intent(in) :: item
    end subroutine push_int_sub

    integer function pop_int_func(this)
      import :: deque
      class(deque), intent(inout) :: this
    end function pop_int_func

    integer function peek_int_func(this)
      import :: deque
      class(deque), intent(in) :: this
    end function peek_int_func
  end interface

  type, extends(deque) :: int_deque
    integer, allocatable :: items(:)
  contains
    procedure :: pushleft => int_deque_pushleft
    procedure :: pushright => int_deque_pushright
    procedure :: popleft => int_deque_popleft
    procedure :: popright => int_deque_popright
    procedure :: peekleft => int_deque_peekleft
    procedure :: peekright => int_deque_peekright
  end type int_deque

contains
  subroutine int_deque_pushleft(this, item)
    class(int_deque), intent(inout) :: this
    integer, intent(in) :: item
    if (.not. allocated(this%items)) then
      allocate(this%items(1))
      this%items(1) = item
    else
      this%items = [item, this%items(:)]
    endif
  end subroutine int_deque_pushleft

  subroutine int_deque_pushright(this, item)
    class(int_deque), intent(inout) :: this
    integer, intent(in) :: item
    if (.not. allocated(this%items)) then
      allocate(this%items(1))
      this%items(1) = item
    else
      this%items = [this%items(:), item]
    endif
  end subroutine int_deque_pushright

  function int_deque_popleft(this) result(item)
    class(int_deque), intent(inout) :: this
    integer :: item
    if (allocated(this%items) .and. size(this%items) > 0) then
      item = this%items(1)
      this%items = this%items(2:size(this%items))
    else
      item = -1 ! Indicate empty or error
    endif
  end function int_deque_popleft

  function int_deque_popright(this) result(item)
    class(int_deque), intent(inout) :: this
    integer :: item
    integer :: n
    n = size(this%items)
    if (n > 0) then
      item = this%items(n)
      if (n > 1) then
        this%items = this%items(1:n-1)
      else
        deallocate(this%items)
      endif
    else
      item = -1 ! Indicate empty or error
    endif
  end function int_deque_popright

  function int_deque_peekleft(this) result(item)
    class(int_deque), intent(in) :: this
    integer :: item
    if (allocated(this%items) .and. size(this%items) > 0) then
      item = this%items(1)
    else
      item = -1 ! Indicate empty or error
    endif
  end function int_deque_peekleft

  function int_deque_peekright(this) result(item)
    class(int_deque), intent(in) :: this
    integer :: item
    if (allocated(this%items) .and. size(this%items) > 0) then
      item = this%items(size(this%items))
    else
      item = -1 ! Indicate empty or error
    endif
  end function int_deque_peekright

end module deque_mod

program test_deque
  use deque_mod
  implicit none

  type(int_deque) :: dq
  integer :: item

  call dq%pushleft(10)
  call dq%pushleft(20)
  call dq%pushright(5)
  call dq%pushright(1)

  ! Peek and pop operations
  item = dq%peekleft()
  print *, 'Peek left:', item
  item = dq%peekright()
  print *, 'Peek right:', item

  item = dq%popleft()
  print *, 'Popped left:', item
  item = dq%popright()
  print *, 'Popped right:', item

end program test_deque