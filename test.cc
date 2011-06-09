//#include <blitz/et-forward.h>
//#include <blitz/array/asexpr.h>
//#include <blitz/prettyprint.h>
//#include <blitz/shapecheck.h>
//#include <blitz/numinquire.h>
//#include <blitz/array/domain.h>
//#include <blitz/array/slice.h>
//#include <blitz/array/expr.h>
//#include <blitz/constpointerstack.h>
//#include <blitz/array/fastiter.h>
#include <blitz/tinyvec2.h>
#include <blitz/tinymat2.h>
#include <blitz/tinymat2.cc>
//#include <blitz/tv2fastiter.h>
//#include <blitz/array/map.h>
//#include <blitz/reduce.h>
//#include <blitz/meta/vecassign.h>
//#include <blitz/array/reduce.h>
//#include <blitz/ops.h>
//#include <blitz/array/ops.h>
//#include <blitz/array/where.h>
#include <blitz/range.h>


#include <blitz/array.h>


#include <blitz/tinyvec2.cc>
//#include <blitz/array.cc>a
#include <blitz/array/stencil-et.h>
#include <blitz/array/stencilops.h>

using namespace blitz;

typedef TinyVector<double,2> tv2;
typedef TinyVector<double,4> tv3;
typedef TinyVector<int,3> it;
typedef Array<double,2> a2;
typedef Array<TinyVector<double,2>,2> atv2;
typedef Array<double,3> a3;
typedef Array<TinyVector<double,3>,3> atv3;
typedef Array<TinyMatrix<double,3,3>,3> atm3;
typedef Array<TinyMatrix<double,2,2>,2> atm2;

tv3 fill() { return tv3(1,3,1,3); }

extern void junk(tv3&, tv3&);

int main(int, char**)
{
  tv3 a=fill();
  tv3 b=fill();
  tv3 c=fill();
  const int N=100;
  const double x=0.2354;
  double s=0;
  for(int i=0;i<N;++i) {
    //blitz::_bz_ArrayExpr<blitz::_bz_ArrayExprBinaryOp<blitz::_bz_ArrayExpr<blitz::FastTV2Iterator<double, 3> >, blitz::_bz_ArrayExpr<blitz::FastTV2Iterator<double, 3> >, blitz::Multiply<double, double> > > xpr(b*c);
    asm("nop;nop;nop;");
    a= a + x*c;
    asm("nop;nop;nop;");
    junk(c,b);
  }
  cout << a << endl;
  cout << s << endl;
}
