
#ifndef VPL_IDE_H
#define VPL_IDE_H

#include <nanovg/nanovg.h>

#define VPL_NSTATE_IDLE (1 << 0)
#define VPL_NSTATE_M1DOWN (1 << 1)
#define VPL_NSTATE_PIN (1 << 2)

#define VPL_ALLOC_WIRES 32768

#define vpl_vec(T, name)                             \
  struct name { T *data; int length, capacity; }

vpl_vec(struct vpl_wire, vec_wire);

struct vpl_ide {
  NVGcontext *nvg;
  int interact_state;

  // used for moving nodes
  float active_hit_x, active_hit_y;
  struct vpl_node *active_node;
  struct vpl_pin  *active_pin;

  // nodes
  int num_nodes;
  struct vpl_node *nodes;

  struct vec_wire vec_wires;
};

void vpl_ide_init(struct vpl_ide *ide);
void vpl_ide_destroy(struct vpl_ide *ide);
void vpl_ide_interact(struct vpl_ide *ide, int m1, float mx, float my);

// wire operations
void vpl_ide_add_wire(struct vpl_ide *ide, struct vpl_wire wire);
void vpl_ide_remove_wire(struct vpl_ide *ide, struct vpl_wire *wire);

#endif /* VPL_IDE_H */
