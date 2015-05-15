/** 
 * @author bulargy.j.bai  
* @创建时间：Mar 9, 2015 
 * @描述：  */ 
public class Math {  
 
public static int divide(int x,int y) {        return x/y; 
      } 
  
 public static int multiple(int x,int y) {        return x*y;       
} 
}
/** 
 * @author bulargy.j.bai  
* @创建时间：Mar 9, 2015
 * @描述：  */ 
public class MathTest {   @BeforeClass 
 public static void setUpBeforeClass() throws Exception {  } 
  @AfterClass 
 public static void tearDownAfterClass() throws Exception {  } 
  @Test 
 public void testDivide() {   fail("Not yet implemented");  } 
  @Test 
 public void testMultiple() {   fail("Not yet implemented");  
 } 
 }
 说明： 
@BeforeClass标签注释的方法用于在整个类测试过程的初始化后调用一次，@AfterClass标签注释的方法则是整个测试类结束之前调用一次。这2个标间的搭配可以避免使用@Before、@After标签组合在每个测试方法前后都调用的弊端，减少系统开销，提高系统测试速度。(不过对环境独立性的测试还是应当使用@Before、@After来完成) 
@Test标签用来标注待测试的方法，按照类中声明的顺序执行。
下面我在上面的测试包中复制一下之前的测试类并且一个改名字叫做MathTestAnother，新建一个class类叫做Uitl4Suite，代码如下：
package org.bj.util; 
import org.junit.runner.RunWith; import org.junit.runners.Suite; 
import org.junit.runners.Suite.SuiteClasses; /** 
 * @author bulargy.j.bai  * @创建时间：Mar 9, 2015  * @描述：  */ 
@RunWith(Suite.class) 
@SuiteClasses({MathTest.class,   
 MathTestAnother.class}) 
public class Util4Suite { 
 }
说明： 
通过@RunWith和@SuiteClasses标签来注释一个空的包含无参数构造函数的类来作为套件
类，将需要组成套件运行的类加到@SuiteClasses的属性中即可。 
修改 testMultiple 
//@Ignore("忽略乘法测试")  @Test 
 
public void testMultiple() {   
 
assertEquals(result,Math.multiple(faciend,multiplicator)); 
 
}
@Parameters 
 public static Collection multipleValues() {   
return Arrays.asList(new Object[][] {   
 {3, 2, 6 },   
 {4, 3, 12 },    
{5, 7, 35 },    
{6, 7, 42 },   
 {11, 7, 77 },    
{25, 4, 100 },    
{34, 3, 102 },    
{21, 5, 105 },    
{11, 22, 242 },    
{8, 9, 72 }});  
}
说明： 
需要使用@Parameters标签注解一个静态的返回集合对象的方法  
增加成员变量和构造函数：
int faciend; 
 int multiplicator; 
 int result; 
  public MathTest(int faciend, int multiplicator, int result) {    
this.faciend = faciend; 
 this.multiplicator = multiplicator;   
 this.result = result; 
 
}
说明： 
注意类型要匹配好，不要搞错了  
最后在给测试类增加如下注释：
@RunWith(Parameterized.class)
