/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __RHONE_PROG_SUBSKEL_H__
#define __RHONE_PROG_SUBSKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct rhone_prog {
	struct bpf_object *obj;
	struct bpf_object_subskeleton *subskel;
	struct {
		struct bpf_map *uprod_ringbuffers;
		struct bpf_map *kprod_ringbuffers;
		struct bpf_map *cpu_dsq_map;
		struct bpf_map *need_tasks_map;
		struct bpf_map *manager_rb;
		struct bpf_map *bss;
		struct bpf_map *data;
		struct bpf_map *rodata_str1_1;
		struct bpf_map *rodata;
		struct bpf_map *rhone;
	} maps;
	struct {
		struct bpf_program *rhone_select_cpu;
		struct bpf_program *rhone_enqueue;
		struct bpf_program *rhone_dispatch;
		struct bpf_program *rhone_consume;
		struct bpf_program *rhone_prep_enable;
		struct bpf_program *rhone_init;
		struct bpf_program *rhone_exit;
	} progs;
	struct rhone_prog__bss {
		bool *exiting;
		bool *schedule_kernel_tasks;
		u32 *bootstrap_rb;
		unsigned long *nr_overflowed;
		unsigned long long *nr_local_enqueued;
		unsigned long long *nr_global_enqueued;
		unsigned long long *nr_local_dispatched;
		unsigned long long *nr_global_dispatched;
		unsigned long long *nr_consumed;
		unsigned long long *nr_global_dsq_dispatched;
		unsigned long long *nr_global_dsq_consumed;
		unsigned long long *nr_kernel_tasks;
	} bss;
	struct rhone_prog__data {
		u32 *consume_batch_size;
	} data;

#ifdef __cplusplus
	static inline struct rhone_prog *open(const struct bpf_object *src);
	static inline void destroy(struct rhone_prog *skel);
#endif /* __cplusplus */
};

static inline void
rhone_prog__destroy(struct rhone_prog *skel)
{
	if (!skel)
		return;
	if (skel->subskel)
		bpf_object__destroy_subskeleton(skel->subskel);
	free(skel);
}

static inline struct rhone_prog *
rhone_prog__open(const struct bpf_object *src)
{
	struct rhone_prog *obj;
	struct bpf_object_subskeleton *s;
	int err;

	obj = (struct rhone_prog *)calloc(1, sizeof(*obj));
	if (!obj) {
		err = -ENOMEM;
		goto err;
	}
	s = (struct bpf_object_subskeleton *)calloc(1, sizeof(*s));
	if (!s) {
		err = -ENOMEM;
		goto err;
	}
	s->sz = sizeof(*s);
	s->obj = src;
	s->var_skel_sz = sizeof(*s->vars);
	obj->subskel = s;

	/* vars */
	s->var_cnt = 13;
	s->vars = (struct bpf_var_skeleton *)calloc(13, sizeof(*s->vars));
	if (!s->vars) {
		err = -ENOMEM;
		goto err;
	}

	s->vars[0].name = "exiting";
	s->vars[0].map = &obj->maps.bss;
	s->vars[0].addr = (void **) &obj->bss.exiting;

	s->vars[1].name = "schedule_kernel_tasks";
	s->vars[1].map = &obj->maps.bss;
	s->vars[1].addr = (void **) &obj->bss.schedule_kernel_tasks;

	s->vars[2].name = "bootstrap_rb";
	s->vars[2].map = &obj->maps.bss;
	s->vars[2].addr = (void **) &obj->bss.bootstrap_rb;

	s->vars[3].name = "nr_overflowed";
	s->vars[3].map = &obj->maps.bss;
	s->vars[3].addr = (void **) &obj->bss.nr_overflowed;

	s->vars[4].name = "nr_local_enqueued";
	s->vars[4].map = &obj->maps.bss;
	s->vars[4].addr = (void **) &obj->bss.nr_local_enqueued;

	s->vars[5].name = "nr_global_enqueued";
	s->vars[5].map = &obj->maps.bss;
	s->vars[5].addr = (void **) &obj->bss.nr_global_enqueued;

	s->vars[6].name = "nr_local_dispatched";
	s->vars[6].map = &obj->maps.bss;
	s->vars[6].addr = (void **) &obj->bss.nr_local_dispatched;

	s->vars[7].name = "nr_global_dispatched";
	s->vars[7].map = &obj->maps.bss;
	s->vars[7].addr = (void **) &obj->bss.nr_global_dispatched;

	s->vars[8].name = "nr_consumed";
	s->vars[8].map = &obj->maps.bss;
	s->vars[8].addr = (void **) &obj->bss.nr_consumed;

	s->vars[9].name = "nr_global_dsq_dispatched";
	s->vars[9].map = &obj->maps.bss;
	s->vars[9].addr = (void **) &obj->bss.nr_global_dsq_dispatched;

	s->vars[10].name = "nr_global_dsq_consumed";
	s->vars[10].map = &obj->maps.bss;
	s->vars[10].addr = (void **) &obj->bss.nr_global_dsq_consumed;

	s->vars[11].name = "nr_kernel_tasks";
	s->vars[11].map = &obj->maps.bss;
	s->vars[11].addr = (void **) &obj->bss.nr_kernel_tasks;

	s->vars[12].name = "consume_batch_size";
	s->vars[12].map = &obj->maps.data;
	s->vars[12].addr = (void **) &obj->data.consume_batch_size;

	/* maps */
	s->map_cnt = 10;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps) {
		err = -ENOMEM;
		goto err;
	}

	s->maps[0].name = "uprod_ringbuffers";
	s->maps[0].map = &obj->maps.uprod_ringbuffers;

	s->maps[1].name = "kprod_ringbuffers";
	s->maps[1].map = &obj->maps.kprod_ringbuffers;

	s->maps[2].name = "cpu_dsq_map";
	s->maps[2].map = &obj->maps.cpu_dsq_map;

	s->maps[3].name = "need_tasks_map";
	s->maps[3].map = &obj->maps.need_tasks_map;

	s->maps[4].name = "manager_rb";
	s->maps[4].map = &obj->maps.manager_rb;

	s->maps[5].name = ".bss";
	s->maps[5].map = &obj->maps.bss;

	s->maps[6].name = ".data";
	s->maps[6].map = &obj->maps.data;

	s->maps[7].name = ".rodata.str1.1";
	s->maps[7].map = &obj->maps.rodata_str1_1;

	s->maps[8].name = ".rodata";
	s->maps[8].map = &obj->maps.rodata;

	s->maps[9].name = "rhone";
	s->maps[9].map = &obj->maps.rhone;

	/* programs */
	s->prog_cnt = 7;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs) {
		err = -ENOMEM;
		goto err;
	}

	s->progs[0].name = "rhone_select_cpu";
	s->progs[0].prog = &obj->progs.rhone_select_cpu;

	s->progs[1].name = "rhone_enqueue";
	s->progs[1].prog = &obj->progs.rhone_enqueue;

	s->progs[2].name = "rhone_dispatch";
	s->progs[2].prog = &obj->progs.rhone_dispatch;

	s->progs[3].name = "rhone_consume";
	s->progs[3].prog = &obj->progs.rhone_consume;

	s->progs[4].name = "rhone_prep_enable";
	s->progs[4].prog = &obj->progs.rhone_prep_enable;

	s->progs[5].name = "rhone_init";
	s->progs[5].prog = &obj->progs.rhone_init;

	s->progs[6].name = "rhone_exit";
	s->progs[6].prog = &obj->progs.rhone_exit;

	err = bpf_object__open_subskeleton(s);
	if (err)
		goto err;

	return obj;
err:
	rhone_prog__destroy(obj);
	errno = -err;
	return NULL;
}

#ifdef __cplusplus
struct rhone_prog *rhone_prog::open(const struct bpf_object *src) { return rhone_prog__open(src); }
void rhone_prog::destroy(struct rhone_prog *skel) { rhone_prog__destroy(skel); }
#endif /* __cplusplus */

#endif /* __RHONE_PROG_SUBSKEL_H__ */