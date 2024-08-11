integer function sum41(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, &
     & p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, &
     & p25, p26, p27, p28, p29, p30, p31, p32, p33, p34, p35, p36, p37, p38, &
     & p39, p40, p41)
        implicit none
        integer p1, p2, p3, p4, p5, p6, p7, p8, p9, p10
        integer p11, p12, p13, p14, p15, p16, p17, p18, p19, p20
        integer p21, p22, p23, p24, p25, p26, p27, p28, p29, p30
        integer p31, p32, p33, p34, p35, p36, p37, p38, p39, p40, p41

        sum41 = p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 + p10 + &
                p11 + p12 + p13 + p14 + p15 + p16 + p17 + p18 + p19 + p20 + &
                p21 + p22 + p23 + p24 + p25 + p26 + p27 + p28 + p29 + p30 + &
                p31 + p32 + p33 + p34 + p35 + p36 + p37 + p38 + p39 + p40 + p41
      end function sum41

      integer function qqqcall(extrn, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, &
     & p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, &
     & p25, p26, p27, p28, p29, p30, p31, p32, p33, p34, p35, p36, p37, p38, &
     & p39, p40, p41)
        implicit none
        integer extrn
        external extrn
        integer p1, p2, p3, p4, p5, p6, p7, p8, p9, p10
        integer p11, p12, p13, p14, p15, p16, p17, p18, p19, p20
        integer p21, p22, p23, p24, p25, p26, p27, p28, p29, p30
        integer p31, p32, p33, p34, p35, p36, p37, p38, p39, p40, p41

        qqqcall = extrn(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, &
     & p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, &
     & p25, p26, p27, p28, p29, p30, p31, p32, p33, p34, p35, p36, p37, p38, &
     & p39, p40, p41)
      end function qqqcall

      program testqqqcall
        implicit none
        integer result, qqqcall, sum41
        external qqqcall, sum41

        result = qqqcall(sum41, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, &
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, &
                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)
        print *, 'Test sum41 via qqqcall: ', result

      end program testqqqcall