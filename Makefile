test:= 87751 49348 54706 48440 50897 74686 12252 73279 71311 78386 30822 82246 22970 49124 22232 5014 32407 64349 56186 71991 69709 16591 11635 16498 25725 28691 51706 71590 12633 67107 53629 62397 97874 66926 79864 26475 98614 26411 79969 7193 15006 19981 26084 96130 17755 76483 2641 2351 88692 13546 75674 19065 56502 68618 10221 74702 90239 91635 39213 33509 20145 22316 75690 22549 30530 89142 1768 5738 12427 30957 27336 51151 57056 31781 55681 55291 16601 9076 30097 46774 39904 44950 5576 33176 96794 77992 69348 90839 64622 51949 14115 44412 46880 58509 57080 54688 67393 53808 55230 63007 74146 87753 29881 95189 54811 21158 9874 76379 22689 37601 22304 11723 72795 18068 33698 98330 56466 9703 71513 24684 38981 93346 98137 4158 29738 95911 27648 39621 97016 64355 44459 60656 10656 48855 77187 37126 70653 53477 65462 28945 27726 21690 70488 39360 13698 88125 60494 50609 33017 91487 16460 42034 89268 22843 70201 45965 10994 64310 10609 86718 45512 2633 53463 57535 96575 36416 99136 75783 57484 4809 93497 92689 50923 42600 39940 46997 34400 69527 23858 22531 48640 84575 85349 11336 40037 71186 93495 13944 78662 1263 30298 43434 83153 86843 62201 82673 42980 67077 44751 89553 59617 74745 7174 94007 99234 12182 16977 31847 59014 90996 35893 99389 35964 78539 24334 57543 29239 96035 92097 44287 52391 91641 76649 43596 73481 94870 13246 86675 99218 67719 86018 98965 77585 62178 53824 93733 20115 12097 63292 16281 69327 51863 69991 64494 82159 87189 54462 85993 56668 40745 56566 79720 14708 99785 88751 73234 84197 3398 2102 55609 629 88605 19805 1277 84736 93696 27359 34861 5212 78870 15694 47438 38862 62995 8953 9881 87565 46857 97550 92386 71040 80935 55774 64094 44120 44229 52353 92389 95317 30000 54399 28008 83763 18532 28102 21060 24723 40773 11598 29522 40152 7886 79130 12031 99840 46086 20042 84292 70713 31572 89080 20243 94891 89605 56021 34372 94112 96191 64016 89986 82829 14202 94848 87955 1671 91026 39313 8993 40432 17008 79352 79808 4113 99204 39368 18076 76519 17491 2651 99016 17789 41501 86305 6301 73239 87105 82441 12017 25243 94326 13658 1664 82512 64570 7940 3497 23391 32805 92780 55275 41880 6394 79103 26931 39390 66865 6210 91486 8001 32661 74225 30195 38454 23291 49532 81813 1636 31276 50266 52720 72215 51627 84868 9934 34233 96983 78216 59534 64032 76417 20926 53724 49429 59081 7092 73387 67625 37690 54132 8939 35513 79144 99378 73549 92786 67901 28293 73801 36346 6211 5260 15828 78775 29243 7153 65054 71669 14343 87935 98856 28327 23027 72724 36708 61770 38612 68164 2014 43157 61348 11382 61809 97843 32222 25809 51255 32127 84017 15930 8725 29359 72356 98281 18393 46670 63258 6055 65953 9944 24674 47793 81866 8352 39636 2152 96595 30589 49750 41388 60772 66873 64509 79406 35161 68617 5430 87342 10154 54218 53134 55680 5585 77238 52627 8468 42007 87528 91236 51223 78227 86412 76071 98053 55969 29271 22997 76220 91176 92904 70211 36747 52867 43244 52437 34456 88941 58989 78748 33566 82525

all:
	gcc src/*.c libft/*.c -o push_swap
	make -C Push_Swap_42/ re
	./push_swap $(test) > my
	./Push_Swap_42/push_swap $(test) > done
	