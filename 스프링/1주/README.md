## 프로젝트 환경설정 관련 정리

스프링 부트 스타터 사이트로 이동해서 스프링 프로젝트 생성 링크>> https://start.spring.io

프로젝트 선택
Project: **Gradle - Groovy** Project

Spring Boot: **3.x.x**

Language: Java

Packaging: Jar

Java: 17 또는 21

Project Metadata

groupId: hello

artifactId: hello-spring

Dependencies: Spring Web, Thymeleaf


### Gradle 전체 설정


```groovy
build.gradle
plugins {
id 'org.springframework.boot' version '2.3.1.RELEASE'
id 'io.spring.dependency-management' version '1.0.9.RELEASE'
id 'java'
}
group = 'hello'
version = '0.0.1-SNAPSHOT'
sourceCompatibility = '11'
repositories {
mavenCentral()
}
dependencies {
implementation 'org.springframework.boot:spring-boot-starter-thymeleaf'
implementation 'org.springframework.boot:spring-boot-starter-web'
testImplementation('org.springframework.boot:spring-boot-starter-test') {
exclude group: 'org.junit.vintage', module: 'junit-vintage-engine'
}
}
test {
useJUnitPlatform()
}
```
### view 환경설정


```html
resources/static/index.html
<!DOCTYPE HTML>
<html>
<head>
<title>Hello</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
</head>
<body>
Hello
<a href="/hello">hello</a>
</body>
</html>
```

### thymeleaf 템플릿 엔진
```java
@Controller
public class HelloController {
@GetMapping("hello")
public String hello(Model model) {
model.addAttribute("data", "hello!!");
return "hello";
}
}
```


```html
resources/templates/hello.html
<!DOCTYPE HTML>
<html xmlns:th="http://www.thymeleaf.org">
<head>
<title>Hello</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
</head>
<body>
<p th:text="'안녕하세요. ' + ${data}" >안녕하세요. 손님</p>
</body>
</html>
```
