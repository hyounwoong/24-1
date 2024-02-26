## 스프링 웹개발 기초
웹개발에 사용되는 방식은 크게 세가지 1.정적컨텐츠 2.MVC,템플릿 엔진 3.API

### 정적컨텐츠

정적컨텐츠란 쉽게 말해웹 애플리케이션에서 동적으로 생성되는 컨텐츠가 아니라, 웹 서버에 이미 저장되어 있는 파일로서 바로 클라이언트에게 제공되는 자원을 말함

스프링 부트 정적 컨텐츠 레퍼런스>> https://docs.spring.io/spring-boot/docs/2.3.1.RELEASE/reference/html/spring-bootfeatures.html#boot-features-spring-mvc-static-content
```html
resources/static/hello-static.html`
<!DOCTYPE HTML>
<html>
<head>
<title>static content</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
</head>
<body>
정적 컨텐츠 입니다.
</body>
</html>
```

실행링크>> http://localhost:8080/hello-static.html


### MVC와 템플릿 엔진

MVC란 Model, View, Controller를 의미한다.

#### Controller
```java
@Controller
public class HelloController {
@GetMapping("hello-mvc")
public String helloMvc(@RequestParam("name") String name, Model model) {
model.addAttribute("name", name);
return "hello-template";
}
}
```

#### View
```html
resources/templates/hello-template.html`
<html xmlns:th="http://www.thymeleaf.org">
<body>
<p th:text="'hello ' + ${name}">hello! empty</p>
</body>
</html>
```
실행링크>> http://localhost:8080/hello-mvc?name=spring

#### API
@ResponseBody 문자 반환

```java
@Controller
public class HelloController {
@GetMapping("hello-string")
@ResponseBody
public String helloString(@RequestParam("name") String name) {
return "hello " + name;
}
}
```
@ResponseBody` 를 사용하면 뷰 리졸버를 사용X

대신에 HTTP의 BODY에 문자 내용을 직접 반환(HTML BODY TAG를 말하는 것이 아님)

실행링크>>http://localhost:8080/hello-string?name=spring

