#include "FRMIDICon.h"
/* Primitive functions (Macros) */
#define _exclamation__eq_(a, b) (a != b)
#define _plus_(a, b) (a + b)
#define _slash_(a, b) (a / b)
#define _anpersand_anpersand(a, b) (a && b)
#define _eq__eq_(a, b) (a == b)
#define _vertial__vertial_(a, b) (a || b)
#define _at__minus_(a) (-a)
#define _at__exclamation_(a) (!a)
/* Data types */
struct Tuple3_OType_Int_Int{
  int mark;
  union {
    struct {
      int member0;
      int member1;
      int member2;
    }Tuple3;
  }value;
};
/* Global variables */
int node_memory_idx[2];
int node_memory_iv[2];
int node_memory_iv_last[2];
int node_memory_play[2];
struct Tuple3_OType_Int_Int* node_memory_anonymous480[2];
int node_memory_note_on[2];
int node_memory_ot[2];
int node_memory_ox[2];
int node_memory_oy[2];
struct Tuple3_OType_Int_Int memory_Tuple3_OType_Int_Int[1];
int size_Tuple3_OType_Int_Int = 1;
int counter_Tuple3_OType_Int_Int = 0;
int Counter = 1;
int NodeSize = 6;
/* Static prototypes */
static struct Tuple3_OType_Int_Int* Tuple3_0(int, int, int);
static void mark_Tuple3_OType_Int_Int(struct Tuple3_OType_Int_Int*, int);
static int node_play(int, int, int, int, int*);
static int init_play();
static int node_anonymous480(int, int, int, int, int, struct Tuple3_OType_Int_Int**);
static int node_note_on(int, int, int, int*);
static int init_note_on();
static int node_ot(struct Tuple3_OType_Int_Int*, int*);
static int node_ox(struct Tuple3_OType_Int_Int*, int*);
static int node_oy(struct Tuple3_OType_Int_Int*, int*);
static void refreshMark();
extern void Input(int*, int*, int*);
extern void Output(int*, int*, int*);
/* Functions, Constructors, GCMarkers, etc... */
static struct Tuple3_OType_Int_Int* Tuple3_0(int member0, int member1, int member2) {
  struct Tuple3_OType_Int_Int* x;
  while (1) {
    counter_Tuple3_OType_Int_Int++;
    counter_Tuple3_OType_Int_Int %= size_Tuple3_OType_Int_Int;
    if (memory_Tuple3_OType_Int_Int[counter_Tuple3_OType_Int_Int].mark < Counter) { x = memory_Tuple3_OType_Int_Int + counter_Tuple3_OType_Int_Int; break; }
  }
  x->mark = 0;
  x->value.Tuple3.member0 = member0;
  x->value.Tuple3.member1 = member1;
  x->value.Tuple3.member2 = member2;
  return x;
}
static void mark_Tuple3_OType_Int_Int(struct Tuple3_OType_Int_Int* x, int mark) {
  if (mark > x->mark) { x->mark = mark; }
}
static int node_play(int iv, int iv_last, int play_at_last, int idx, int* output) {
  int _tmp000;
  if (idx == 9) {
    int _tmp002;
    int _tmp001;
    _tmp002 = _anpersand_anpersand(_eq__eq_(iv, 0), _exclamation__eq_(iv_last, 0));
    if (_tmp002 == 1) {
      _tmp001 = _at__exclamation_(play_at_last);
    }
    else {
      _tmp001 = play_at_last;
    }
    _tmp000 = _tmp001;
  }
  else {
    _tmp000 = play_at_last;
  }
  *output = _tmp000;
  return 1;
}
static int init_play() {
  return 0;
}
static int node_anonymous480(int iv, int iv_last, int play, int note_on_at_last, int idx, struct Tuple3_OType_Int_Int** output) {
  struct Tuple3_OType_Int_Int* _tmp003;
  if (idx == 0) {
    int _tmp005;
    struct Tuple3_OType_Int_Int* _tmp004;
    _tmp005 = _exclamation__eq_(iv, iv_last);
    if (_tmp005 == 1) {
      _tmp004 = Tuple3_0(1, 56, iv);
    }
    else {
      _tmp004 = Tuple3_0(0, 0, 0);
    }
    _tmp003 = _tmp004;
  }
  else if (idx == 1) {
    int _tmp007;
    struct Tuple3_OType_Int_Int* _tmp006;
    _tmp007 = _exclamation__eq_(iv, iv_last);
    if (_tmp007 == 1) {
      _tmp006 = Tuple3_0(1, 57, iv);
    }
    else {
      _tmp006 = Tuple3_0(0, 1, 0);
    }
    _tmp003 = _tmp006;
  }
  else if (idx == 2) {
    int _tmp009;
    struct Tuple3_OType_Int_Int* _tmp008;
    _tmp009 = _exclamation__eq_(iv, iv_last);
    if (_tmp009 == 1) {
      _tmp008 = Tuple3_0(1, 58, iv);
    }
    else {
      _tmp008 = Tuple3_0(0, 2, 0);
    }
    _tmp003 = _tmp008;
  }
  else if (idx == 3) {
    int _tmp011;
    struct Tuple3_OType_Int_Int* _tmp010;
    _tmp011 = _exclamation__eq_(iv, iv_last);
    if (_tmp011 == 1) {
      _tmp010 = Tuple3_0(1, 59, iv);
    }
    else {
      _tmp010 = Tuple3_0(0, 3, 0);
    }
    _tmp003 = _tmp010;
  }
  else if (idx == 4) {
    int _tmp013;
    struct Tuple3_OType_Int_Int* _tmp012;
    _tmp013 = _exclamation__eq_(iv, iv_last);
    if (_tmp013 == 1) {
      _tmp012 = Tuple3_0(1, 25, iv);
    }
    else {
      _tmp012 = Tuple3_0(0, 4, 0);
    }
    _tmp003 = _tmp012;
  }
  else if (idx == 5) {
    int _tmp015;
    struct Tuple3_OType_Int_Int* _tmp014;
    _tmp015 = _exclamation__eq_(iv, iv_last);
    if (_tmp015 == 1) {
      _tmp014 = Tuple3_0(1, 16, iv);
    }
    else {
      _tmp014 = Tuple3_0(0, 5, 0);
    }
    _tmp003 = _tmp014;
  }
  else if (idx == 6) {
    int _tmp017;
    struct Tuple3_OType_Int_Int* _tmp016;
    _tmp017 = _exclamation__eq_(iv, iv_last);
    if (_tmp017 == 1) {
      _tmp016 = Tuple3_0(1, 17, iv);
    }
    else {
      _tmp016 = Tuple3_0(0, 6, 0);
    }
    _tmp003 = _tmp016;
  }
  else if (idx == 7) {
    int _tmp019;
    struct Tuple3_OType_Int_Int* _tmp018;
    _tmp019 = _exclamation__eq_(iv, iv_last);
    if (_tmp019 == 1) {
      _tmp018 = Tuple3_0(1, 82, _plus_(_slash_(iv, 2), 64));
    }
    else {
      _tmp018 = Tuple3_0(0, 7, 0);
    }
    _tmp003 = _tmp018;
  }
  else if (idx == 8) {
    int _tmp021;
    struct Tuple3_OType_Int_Int* _tmp020;
    _tmp021 = _anpersand_anpersand(_eq__eq_(iv, 0), _exclamation__eq_(iv_last, 0));
    if (_tmp021 == 1) {
      _tmp020 = Tuple3_0(2, 45, 127);
    }
    else {
      int _tmp023;
      struct Tuple3_OType_Int_Int* _tmp022;
      _tmp023 = _anpersand_anpersand(_exclamation__eq_(iv, 0), _eq__eq_(iv_last, 0));
      if (_tmp023 == 1) {
        _tmp022 = Tuple3_0(3, 45, 0);
      }
      else {
        _tmp022 = Tuple3_0(0, 8, 0);
      }
      _tmp020 = _tmp022;
    }
    _tmp003 = _tmp020;
  }
  else if (idx == 9) {
    _tmp003 = Tuple3_0(0, 9, 0);
  }
  else if (idx == 10) {
    int _tmp025;
    struct Tuple3_OType_Int_Int* _tmp024;
    _tmp025 = _anpersand_anpersand(_exclamation__eq_(iv, 0), _eq__eq_(iv_last, 0));
    if (_tmp025 == 1) {
      _tmp024 = Tuple3_0(1, 123, 0);
    }
    else {
      _tmp024 = Tuple3_0(0, 10, 0);
    }
    _tmp003 = _tmp024;
  }
  else if (idx == 11) {
    struct Tuple3_OType_Int_Int* _tmp026;
    if (play == 1) {
      _tmp026 = Tuple3_0(2, iv, 127);
    }
    else {
      _tmp026 = Tuple3_0(0, 11, 0);
    }
    _tmp003 = _tmp026;
  }
  else if (idx == 12) {
    int _tmp028;
    struct Tuple3_OType_Int_Int* _tmp027;
    _tmp028 = _vertial__vertial_(play, note_on_at_last);
    if (_tmp028 == 1) {
      _tmp027 = Tuple3_0(3, iv, 0);
    }
    else {
      _tmp027 = Tuple3_0(0, 12, 0);
    }
    _tmp003 = _tmp027;
  }
  else {
    _tmp003 = Tuple3_0(0, _at__minus_(1), 0);
  }
  *output = _tmp003;
  return 1;
}
static int node_note_on(int play, int note_on_at_last, int idx, int* output) {
  int _tmp029;
  if (idx == 11) {
    int _tmp030;
    if (play == 1) {
      _tmp030 = 1;
    }
    else {
      _tmp030 = note_on_at_last;
    }
    _tmp029 = _tmp030;
  }
  else if (idx == 12) {
    int _tmp032;
    int _tmp031;
    _tmp032 = _vertial__vertial_(play, note_on_at_last);
    if (_tmp032 == 1) {
      _tmp031 = 0;
    }
    else {
      _tmp031 = note_on_at_last;
    }
    _tmp029 = _tmp031;
  }
  else {
    _tmp029 = note_on_at_last;
  }
  *output = _tmp029;
  return 1;
}
static int init_note_on() {
  return 0;
}
static int node_ot(struct Tuple3_OType_Int_Int* anonymous480, int* output) {
  int _tmp033;
  if (1) {
    int pvar0_ot = anonymous480->value.Tuple3.member0;
    int pvar0_ox = anonymous480->value.Tuple3.member1;
    int pvar0_oy = anonymous480->value.Tuple3.member2;
    _tmp033 = pvar0_ot;
  }
  *output = _tmp033;
  return 1;
}
static int node_ox(struct Tuple3_OType_Int_Int* anonymous480, int* output) {
  int _tmp034;
  if (1) {
    int pvar1_ot = anonymous480->value.Tuple3.member0;
    int pvar1_ox = anonymous480->value.Tuple3.member1;
    int pvar1_oy = anonymous480->value.Tuple3.member2;
    _tmp034 = pvar1_ox;
  }
  *output = _tmp034;
  return 1;
}
static int node_oy(struct Tuple3_OType_Int_Int* anonymous480, int* output) {
  int _tmp035;
  if (1) {
    int pvar2_ot = anonymous480->value.Tuple3.member0;
    int pvar2_ox = anonymous480->value.Tuple3.member1;
    int pvar2_oy = anonymous480->value.Tuple3.member2;
    _tmp035 = pvar2_oy;
  }
  *output = _tmp035;
  return 1;
}
static void refreshMark() {
  int i;
  for (i = 0; i < size_Tuple3_OType_Int_Int; i++) {
    if (memory_Tuple3_OType_Int_Int[i].mark < Counter) memory_Tuple3_OType_Int_Int[i].mark = 0;
    else memory_Tuple3_OType_Int_Int[i].mark -= Counter - 1;
  }
}
void ActivateFRMIDICon() {
  int current_side = 0, last_side = 1;
  node_memory_play[last_side] = init_play();
  node_memory_note_on[last_side] = init_note_on();
  Counter = NodeSize + 1;
  refreshMark();
  while (1) {
    Counter = 1;
    Input(&node_memory_idx[current_side], &node_memory_iv[current_side], &node_memory_iv_last[current_side]);
    node_play(node_memory_iv[current_side], node_memory_iv_last[current_side], node_memory_play[last_side], node_memory_idx[current_side], &node_memory_play[current_side]);
    Counter++;
    node_anonymous480(node_memory_iv[current_side], node_memory_iv_last[current_side], node_memory_play[current_side], node_memory_note_on[last_side], node_memory_idx[current_side], &node_memory_anonymous480[current_side]);
    mark_Tuple3_OType_Int_Int(node_memory_anonymous480[current_side], Counter + 4);
    Counter++;
    node_note_on(node_memory_play[current_side], node_memory_note_on[last_side], node_memory_idx[current_side], &node_memory_note_on[current_side]);
    Counter++;
    node_ot(node_memory_anonymous480[current_side], &node_memory_ot[current_side]);
    Counter++;
    node_ox(node_memory_anonymous480[current_side], &node_memory_ox[current_side]);
    Counter++;
    node_oy(node_memory_anonymous480[current_side], &node_memory_oy[current_side]);
    Counter++;
    Output(&node_memory_ot[current_side], &node_memory_ox[current_side], &node_memory_oy[current_side]);
    refreshMark();
    current_side ^= 1;
    last_side ^= 1;
  }
}
