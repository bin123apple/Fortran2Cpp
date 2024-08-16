program DRB102_copyprivate_orig_no
    use omp_lib
    use DRB102
    implicit none

    !$omp parallel
        !$omp single
        x=1.0
        y=1
        !$omp end single copyprivate(x,y)
    !$omp end parallel

    print 100, x, y
    100 format ('x =',F3.1,2x,'y =',i3)

end program
