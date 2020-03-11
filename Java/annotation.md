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
코드에 적용할 때는  
```java

@AnnotationName(elementName1 = "값", elementName2 = 3);

```

### 어노테이션 적용 대상
* 어노테이션을 적용할 수 있는 대상은 java.lang.annotation.ElementType 열거 상수로 정의되어 있음
* 어노테이션이 적용될 대상을 지정할 때에는 @Target 어노테이션을 사용.
 * @Target의 기본 엘리먼트인 value는 ElementType 배열을 값으로 가짐.(어노테이션이 적용될 대상을 복수 개로 지정하기 위해서)


```java
@Target({ElementType.TYPE, ElementType.FIELD, ElementType.METHOD}) 
public @interface AnnotationName {

}
```
과 같이 정의한다면 클래스, 필드, 메소드만 어노테이션을 적용할 수 있고 생성자는 적용할 수 없음

### 어노테이션 유지 정책
* 리플렉션이란 런타임 시에 클래스의 메타 정보를 얻는 기능을 말함.
 * 클래스가 가지고 있는 필드가 무엇인지, 어떤 생성자를 갖고 있는지, 어떤 메소드를 갖고 있는지, 적용된 어노테이션이 무엇인지 알아내는 것이 리플렉션
* 리플렉션을 이용해서 런타임 시에 어노테이션 정보를 얻으려면 어노테이션 유지 정책을 RUNTIME으로 설정

```java
//런타임 유지정책을 적용한 어노테이션
@Target({Element.Type.TYPE, ElementType.FIELD, ElementType.METHOD})
@Retention(RetentionPolicy.RUNTIME)
public @interface AnnotationName {

}
```
