module my_module
    implicit none

    type :: MyClass
        integer :: columns
        integer :: hash_size
    contains
        procedure :: updateHashSizeAndBuckets
    end type MyClass

contains

    subroutine updateHashSizeAndBuckets(this, sparsity)
        class(MyClass), intent(inout) :: this
        real, intent(in) :: sparsity
        integer :: num_buckets

        this%hash_size = int(1.0 / sparsity)
        if (this%hash_size > this%columns) this%hash_size = this%columns
        num_buckets = this%columns / this%hash_size + 1

        print *, 'num_buckets = ', num_buckets
    end subroutine updateHashSizeAndBuckets

end module my_module

program test_program
    use my_module
    implicit none

    type(MyClass) :: obj

    ! Initialize with some values
    obj%columns = 100

    ! Run test case 1
    print *, 'Test Case 1:'
    call obj%updateHashSizeAndBuckets(0.05)

    ! Run test case 2
    obj%columns = 50
    print *, 'Test Case 2:'
    call obj%updateHashSizeAndBuckets(0.1)

end program test_program