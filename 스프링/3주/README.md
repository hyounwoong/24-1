## 회원관리예제

### 비즈니스 요구사항 정리

데이터: 회원ID, 이름

기능: 회원 등록, 조회

아직 데이터 저장소 선정 x

컨트롤러: 웹 MVC의 컨트롤러 역할

서비스: 핵심 비즈니스 로직 구현

리포지토리: 데이터베이스에 접근, 도메인 객체를 DB에 저장하고 관리

도메인: 비즈니스 도메인 객체, 예) 회원, 주문, 쿠폰 등등 주로 데이터베이스에 저장하고 관리됨

아직 데이터 저장소가 선정되지 않아서, 우선 인터페이스로 구현 클래스를 변경할 수 있도록 설계

데이터 저장소는 RDB, NoSQL 등등 다양한 저장소를 고민중인 상황으로 가정

개발을 진행하기 위해서 초기 개발 단계에서는 구현체로 가벼운 메모리 기반의 데이터 저장소 사용

### 회원 도메인과 리포지토리
```java
package hello.hellospring.domain;
public class Member {
private Long id;
private String name;
public Long getId() {
return id;
}
public void setId(Long id) {
this.id = id;
}
public String getName() {
return name;
}
public void setName(String name) {
this.name = name;
}
}
```

### 회원레포지토리 인터페이스
```java
package hello.hellospring.repository;
import hello.hellospring.domain.Member;
import java.util.List;
import java.util.Optional;
public interface MemberRepository {
Member save(Member member);
Optional<Member> findById(Long id);
Optional<Member> findByName(String name);
List<Member> findAll();
}
```
### 회원 리포지토리 메모리 구현체
```java
package hello.hellospring.repository;
import hello.hellospring.domain.Member;
import java.util.*;
/**
* 동시성 문제가 고려되어 있지 않음, 실무에서는 ConcurrentHashMap, AtomicLong 사용 고려
*/
public class MemoryMemberRepository implements MemberRepository {
private static Map<Long, Member> store = new HashMap<>();
private static long sequence = 0L;
@Override
public Member save(Member member) {
member.setId(++sequence);
store.put(member.getId(), member);
return member;
}
@Override
public Optional<Member> findById(Long id) {
return Optional.ofNullable(store.get(id));
}
@Override
public List<Member> findAll() {
return new ArrayList<>(store.values());
}
@Override
public Optional<Member> findByName(String name) {
return store.values().stream()
.filter(member -> member.getName().equals(name))
.findAny();
}
public void clearStore() {
store.clear();
}
}
```

### 회원 리포지토리 테스트 케이스 작성
개발한 기능을 실행해서 테스트 할 때 자바의 main 메서드를 통해서 실행하거나, 웹 애플리케이션의 컨트롤러를 통해

서 해당 기능을 실행한다. 이러한 방법은 준비하고 실행하는데 오래 걸리고, 반복 실행하기 어렵고 여러 테스트를 한번

에 실행하기 어렵다는 단점이 있다. 자바는 JUnit이라는 프레임워크로 테스트를 실행해서 이러한 문제를 해결한다.

>>이부분은 생략하자
