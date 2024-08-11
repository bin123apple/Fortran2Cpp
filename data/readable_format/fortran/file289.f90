module TransferBug
    implicit none

    type :: ByteType
        character(len=1) :: singleByte
    end type ByteType

    type (ByteType), allocatable :: BytesPrototype(:)

contains

    function StringToBytes(v) result(bytes)
        character(len=*), intent(in) :: v
        type(ByteType), allocatable :: bytes(:)
        integer :: i

        allocate(bytes(len(v)))
        do i = 1, len(v)
            bytes(i)%singleByte = v(i:i)
        end do
    end function StringToBytes

    subroutine BytesToString(bytes, string)
        type(ByteType), intent(in) :: bytes(:)
        character(len=*), intent(out) :: string
        integer :: numChars, i

        numChars = size(bytes)
        string = ''
        do i = 1, numChars
            string(i:i) = bytes(i)%singleByte
        end do
    end subroutine BytesToString

    subroutine TestConversion()
        character(len=100) :: testStr = "Hello, world!"
        character(len=100) :: resultStr
        call BytesToString(StringToBytes(testStr), resultStr)
        if (trim(resultStr) /= trim(testStr)) then
            print *, "Test Failed: ", trim(testStr), " != ", trim(resultStr)
        else
            print *, "Test Passed: ", trim(testStr), " = ", trim(resultStr)
        end if
    end subroutine TestConversion

end module TransferBug

program main
    use TransferBug
    implicit none

    call TestConversion()

end program main