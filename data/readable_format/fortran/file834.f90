module functioncall
  implicit none

  private

  interface general_func
    module procedure func_dim1
    module procedure func_dim2
  end interface

  public :: general_func

contains

  subroutine func_dim1( arr )
    integer, dimension( 1:2 )        :: arr

    write( * , * ) "inside func_dim1"
    write( * , * ) shape(arr)
    write( * , * ) arr

  end subroutine func_dim1

  subroutine func_dim2( arr )
    integer, dimension( 1:2, 1:2 )   :: arr

    write( * , * ) "inside func_dim2"
    write( * , * ) shape(arr)
    write( * , * ) arr

  end subroutine func_dim2

end module functioncall

program arbitarydimensionstest
  use functioncall
  implicit none

  integer, dimension( 1:2 )         :: dim1
  integer, dimension( 1:2, 1:2 )    :: dim2

  dim1 = (/ 1, 2 /)
  dim2 = reshape((/ 1, 2, 3, 4 /), shape(dim2))

  write( * , * ) ">> output of func_dim1 - array:"
  call general_func( dim1 )

  write( * , * ) ">> output of func_dim2 - array:"
  call general_func( dim2 )

end program arbitarydimensionstest