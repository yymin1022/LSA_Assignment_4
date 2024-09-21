## Linux Kernel optimized for 384 bytes Memory Allocation

### Description
본 프로젝트는 `5.14.214 LTS` 리눅스 커널을 기반으로 기존의 `Slab` 메모리 할당자 수정을 통해 `384 bytes` 크기의 메모리 할당 효율성을 개선한 프로젝트입니다.<br/>
기존 커널의 경우, `256 bytes`와 `512 bytes` 사이의 블럭 할당 단위가 정의되어있지 않은 관계로, `384 bytes` 크기의 메모리 할당을 요청하는 경우, 내부적으로는 `512 bytes`의 블럭이 할당됩니다.<br/>
따라서, `384 bytes` 크기를 반복적으로 다수 요청하는 특정한 환경에서는 불필요한 메모리 사용량이 증가하는 문제가 있으며, 이를 개선하고자 새로운 크기의 `Slab` 할당 단위를 추가 정의하였습니다.

본 프로젝트를 테스트하기 위한 커널 모듈은 다음 레포에서 확인하실 수 있습니다.<br/>
[LSA_kmalloc_384_test Repository](https://github.com/yymin1022/LSA_kmalloc_384_test/)

---

### Result

`384 bytes` 크기 할당자의 효율성을 테스트하기에 앞서, 먼저 기존의 `512 bytes`로 할당이 이루어지는 순정 커널에서의 모듈 실행 결과입니다.<br/>
테스트는 상기에서 언급한 커널 모듈을 기반으로 진행하였으며, 모듈을 실행하는 경우 `384 bytes` 크기의 할당 요청이 409600회 진행됩니다.

<img src="image/result_before_512.png" width="75%" />

총 `209,715,200 bytes`의 할당이 이루어졌습니다.<br/>
다음은 `384 bytes` 크기의 할당자 단위를 추가로 구현한 본 프로젝트에서 제작한 커널의 테스트 결과입니다.

<img src="image/result_after_384.png" width="75%" />

총 `152,286,400 bytes`로 약 25%의 메모리가 절약된 것을 확인할 수 있습니다.

---

### Team
| [유용민](https://github.com/yymin1022) | [채승운](https://github.com/win-luck) | [박지우](https://github.com/pjw-redt) | [손유진](https://github.com/causyj) |
| --- | --- | --- | --- |
| <img src="image/profile_yymin1022.png" width="150" /> | <img src="image/profile_win-luck.png" width="150" /> | <img src="image/profile_pjw-redt.png" width="150" /> | <img src="image/profile_causyj.png" width="150" height="150" style="object-fit: cover;"/> |
| Leader / Kernel 개발 / Kernel Module 개발 | kmalloc 관련 자료 분석 | Slab 관련 자료 분석 | 발표 및 자료 분석 |
| 소프트웨어학부 "19 | 소프트웨어학부 "19 | 소프트웨어학부 "21 | 소프트웨어학부 "21 |

---

### README.md Content from Original Linux Kernel Project
```
Linux kernel
============

There are several guides for kernel developers and users. These guides can
be rendered in a number of formats, like HTML and PDF. Please read
Documentation/admin-guide/README.rst first.

In order to build the documentation, use ``make htmldocs`` or
``make pdfdocs``.  The formatted documentation can also be read online at:

    https://www.kernel.org/doc/html/latest/

There are various text files in the Documentation/ subdirectory,
several of them using the Restructured Text markup notation.

Please read the Documentation/process/changes.rst file, as it contains the
requirements for building and running the kernel, and information about
the problems which may result by upgrading your kernel.
```
