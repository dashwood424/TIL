## Annotation
* 컴파일 과정과 실행 과정에서 코드를 어떻게 컴파일하고 처리할 것인지를 알려주는 정보  
* 컴파일러에게 코드 문법 에러를 체크하도록 정보 제공
  * ex) @Override
* 소프트웨어 개발 툴이 빌드나 배치 시 코드를 자동으로 생성할 수 있도록 정보 제공
* 실행 시 특정 기능을 실행하도록 정보를 제공
* 빌드 시 자동으로 XML 설정 파일을 생성하거나, 배포를 위해 JAR 압축 파일을 생성하는데에도 사용
* 실행 시 클래스의 역할을 정의하기도 함

### 어노테이션 타입 정의와 적용
```java
public @interface AnnotationName{
}
```  
이렇게 정의한 어노테이션은 코드에서  
```
@AnnotationName
```
이렇게 사용  
  
어노테이션은 element를 멤버로 가질 수 있음  
```java
public @interface AnnotationName{
  String elementName1();
  int elementName2() default 5;
}

```
