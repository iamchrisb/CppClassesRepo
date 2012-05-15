#include <stdio.h>
#include <assert.h>


#include "rationalnumber.h"
#include "rationalnumberarray.h"

using namespace rnum;


int main()
{

    printf("Performing unit tests for RationalNumber...");
    fflush(stdout);

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1( 3, 4 ),
                    n2( 6, 4 ),
                    n3( 3, 2 ),
                    n4( -9, -6 ),
                    n5( 9, -6 ),
                    n6( 9, 4 ),
                    n0( 0, 4 ),

                    nadd1( 1, 5),
                    nadd2( 1 , 3),
                    nresult( 8 , 15 ),

                    nresultmul(1 , 15),

                    nn( 4, 0 );

    double          d1 = 1.2,
                    d2 = 0.3,
                    d3 = 0.75;

    int             i1 = 1,
                    i2 = 0,
                    i3 = 6,
                    i4 = 11,
                    i5 = 47;

    RationalNumberArray rna1(5);
    RationalNumberArray rna2(5);

    // Test Valid & NAN
    assert( n0.isValid() );
    assert( !nn.isValid() );
    assert( nn.isNaN() );

    // Test Equals
    assert( n2.equal(n3) );
    assert( !n2.equal(n1) );
    assert( n2.equal(n2) );

    assert( !n3.equal(n0) );
    assert( n4.equal(n3) );

    // Test append with Operator ==
    rna2.append(n1);
    assert(rna2.get(0)==n1);
    rna2.append(n2);
    assert(rna2.get(1)==n2);
    rna2.append(n3);
    assert(rna2.get(2)==n3);
    rna2.append(n1);
    assert(rna2.get(3)==n1);
    rna2.append(n2);
    assert(rna2.get(4)==n2);
    rna2.append(n3);
    assert(rna2.get(5)==n3);

    // Test ob Size und Capacity richtig erhöht wurde
    assert(rna2.getSize() == i3);
    assert(rna2.getCapacity() == i4);
    // Test set-Methode inklusive resize-Aufruf, da position > capacity
    rna2.set(n0,12);
    assert(rna2.getCapacity() == i5);

    rna2.printRNA();

    // Test set-Methode
    rna1.set(n0,0);
    assert(rna1.get(0).equal(n0));

    // Test resize-Methode und set
    rna1.resize(7);
    rna1.set(n1,6);
    assert(rna1.get(6).equal(n1));

    // Test ob Size und Capacity richtig erhöht wurde
    assert(rna1.getSize() == (i3+1));
    assert(rna1.getCapacity() == (i3+1));


    // Test Operator <= rn,rn rn,double rn,int
    assert( n1<=n2 );
    assert( n3<=n4 );
    assert( !(n2<=n5) );

    assert( n1<=d1 );
    assert( n1<=d3 );
    assert( !(n3<=d2) );

    assert( n1<=i1 );
    assert( !(n3<=i2) );

    // Test Operator >= rn,rn rn,double rn,int
    assert( !(n1>=n2) );
    assert( n3>=n4 );
    assert( n2>=n5 );

    assert( !(n1>=d1) );
    assert( n1>=d3 );
    assert( n3>=d2 );

    assert( !(n1>=i1) );
    assert( n3>=i2 );




    /** Test Sub **/
    RationalNumber rsub1(3,4);
    RationalNumber rsub2(1,4);
    RationalNumber rsubresult(2,4);

    assert((rsub1-rsub2)==rsubresult);
   // assert(());

    /** Test Mul **/
    RationalNumber rmul1(2,5);
    RationalNumber rmul2(1,3);
    RationalNumber rmulresult(2,15);

    //assert (rmul1.mul(rmul2).equal(rmulresult));

    /** Test Div **/

    RationalNumber rdiv1(1,5);
    RationalNumber rdiv2(1,3);
    RationalNumber rdivresult(3,5);

    //assert(rdiv1.div(rdiv2).equal(rdivresult));

    /** Test less **/

    RationalNumber rless1(-2 , -5);
    RationalNumber rless2(-1,2);

    //assert(rless2.lessThan(rless1));

/*
    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDivide(n3,n3);
    RationalNumber t3 = rnDivide(n2,n2);
    RationalNumber t4 = rnDivide(n6,n0);

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( rnIsNaN(t4) );

    printf(" successful!\n");
    //Ende Code Schirmacher

    printf("Test RNA... ");

    RationalNumberArray* rna0 = rnaCreate(5);
    RationalNumber rn10(1,2);
    RationalNumber rn20(3,5);
    RationalNumber rn30(1,4);

    assert(rnaSize(rna0)==0);

    rnaAdd(rna0,&rn10);
    rnaAdd(rna0,&rn20);

    assert(rnaSize(rna0)==2);
    assert(rnaCapacity(rna0)==5);

    rnaSet(rna0, &rn30,6);

    assert(rnaSize(rna0)==7);
    assert(rnaCapacity(rna0)==11);

    rnaRemove(rna0,4,9);

    assert(rnaCapacity(rna0)==5);
    assert(rnaSize(rna0)==2);

    rnaDelete(rna0);
*/
    printf(" successful!\n");
/*
    // Code von Oliver Schobel und Richard Rutsche
    printf("Performing unit tests for RationalNumberArray...");

         // Part 2 - RationalNumberArray type

            printf("\n");

            RationalNumber *rn1 = &n1;
            RationalNumber *rn2 = &n2;
            RationalNumber *rn3 = &n3;
            RationalNumber *rn4 = &n4;
            RationalNumber *rn5 = &nn;
            RationalNumber *rn6 = 0;
            RationalNumberArray *rna = rnaCreate(10);

            rnaSet(rna,rn1,0);
            rnaSet(rna,rn2,3);
            rnaSet(rna,rn3,6);
            rnaSet(rna,rn4,8);

            assert(rnEqual(n1,*rnaGet(rna,0)));
            assert(rnEqual(n2,*rnaGet(rna,3)));
            assert(rnEqual(n3,*rnaGet(rna,6)));
            assert(rnEqual(n3,*rnaGet(rna,8)));

            rnaRemove(rna,0,3);

            assert(!rnEqual(n1,*rnaGet(rna,0)));
            assert(rnEqual(n2,*rnaGet(rna,3)));
            assert(6 == rnaSize(rna));

            rnaSet(rna, rn1, 14);

            assert(15 == rnaSize(rna));
            assert(15 < rnaCapacity(rna));

            rnaAdd(rna, rn2);

            assert(rnEqual(n2,*rnaGet(rna,rnaSize(rna)-1)));

            rnaSet(rna, rn4, 2);
            rnaResize(rna, 5);

            assert(3 == rnaSize(rna));
            assert(5 == rnaCapacity(rna));
            assert(rnEqual(n4, *rnaGet(rna, 2)));

            rnaResize(rna, 15);

            assert(3 == rnaSize(rna));
            assert(15 == rnaCapacity(rna));
            assert(rnEqual(n4, *rnaGet(rna, 2)));

            rnaAdd(rna, rn5);

            //Ende von Code von Oliver Schobel und Richard Rutsche

            rnaAdd(rna, rn6);
            assert(3 == *rnaError(rna));//NoRN
            rnaDelete(rna);

            printf(" successful!\n");
*/
    return 0;
}
