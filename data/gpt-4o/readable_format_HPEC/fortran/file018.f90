program DRB087_static_data_member2_orig_yes
    use omp_lib
    use DRB087
    implicit none

    type(A) :: c
    c = A(0,0)

    !$omp parallel
    counter = counter+1
    pcounter = pcounter+1
    !$omp end parallel

    print *,counter,pcounter
end program
