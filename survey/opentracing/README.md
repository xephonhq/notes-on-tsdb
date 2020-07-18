# Opentracing

It is not database ... but part of the observability family ...

copied from go.ice ... well it's long time ago

## TODO

- [ ] `opentracing.StartSpanFromContext` is using `opentracing.GlobalTracer()`, what's the better alternative? `SpanFromContext`
- [ ] set global tag for a service, i.e. `aws-region` etc.
- [ ] Is it possible to have cycle in service dependencies, i.e. the cycle is break based on certain flags

## Tutorial

https://github.com/yurishkuro/opentracing-tutorial/tree/master/go

Lesson 01

- `opentracing.GlobalTracer` default is a noop tracer
- tags are meant to describe attributes of the span that apply to the whole duration of the span
- log is for timestamped event
  - `LogFields` is for zero allocation (like zap I suppose ...) TODO: I don't think those extra work really boost performance
  - `LogKV` takes k,v pair
- [ ] FIXME: typo in README.md, `previosuly` should be `previously`

Lesson 02

- `rootSpan.Tracer().StartSpan("span-name")` would create a entire new trace instead of a child of rootSpan
- `rootSpan.Tracer().StartSpan("span-name", opentracing.ChildOf(rootSpan.Context()))` would create child
- edge in the DAG is `SpanReference`, there are two `ReferenceType`, 
  - `ChildOf`, rootSpan has a logical dependency on the child before it can complete its operation
  - `FollowsFrom` rootSpan is the ancestor, but it does not wait for the child to finish, i.e. a best-effort, fire-and-forget cache write
- [ ] FIXME: typo in README.md line 96, should be `rootSpan.Context()` instead of `span.Context()`
- [x] **FIXED**: fatal `opentracing.StartSpanFromContext` is using `opentracing.GlobalTracer()`
  - we should fix this when doing tracing in go.ice, no reason to use `GlobalTracer`
  - [ ] there might be fix in following lessons, or existing codebase ...
 
Lesson 03

- trace both client and server (across process)
  - client side need to `Inject` data into carrier (i.e. HTTP Header)
  - server side need to `Extract` to start span using the trace information passed in carrier (i.e. HTTP Header)
- [x] TODO: are tags on client side span passed to server? I guess not? no

Lesson 04

- use baggage to pass data along the entire trace
- remember not to have typo in baggage name ....

Finished tutorial is in https://github.com/at15/opentracing-tutorial w/o extra credit

## Example HotRod

- https://github.com/jaegertracing/jaeger/blob/master/examples/hotrod/pkg/tracing/init.go#L31 `Init` creates a new instance of Jaeger tracer
- `SamplerConfig`, source code has detail about sampler types `const`, `probabilistic`, `rateLimiting`, `remote`
  - [ ] `SamplingServerURL` ... does this need to be set? seems only needed when using `remote`?

````go
// Init creates a new instance of Jaeger tracer.
func Init(serviceName string, metricsFactory metrics.Factory, logger log.Factory, hostPort string) opentracing.Tracer {
	cfg := config.Configuration{
		Sampler: &config.SamplerConfig{
			Type:  "const",
			Param: 1,
		},
		Reporter: &config.ReporterConfig{
			LogSpans:            false,
			BufferFlushInterval: 1 * time.Second,
			LocalAgentHostPort: hostPort,
		},
	}
	tracer, _, err := cfg.New(
		serviceName,
		config.Logger(jaegerLoggerAdapter{logger.Bg()}),
		config.Observer(rpcmetrics.NewObserver(metricsFactory, rpcmetrics.DefaultNameNormalizer)),
	)
	if err != nil {
		logger.Bg().Fatal("cannot initialize Jaeger Tracer", zap.Error(err))
	}
	return tracer
}
````